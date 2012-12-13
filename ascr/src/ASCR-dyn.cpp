// ASCR
// Carlo Angiuli

#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/Module.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Instructions.h"
#include "llvm/Support/InstVisitor.h"
#include "llvm/Constants.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Instruction.h"
#include "llvm/Support/raw_ostream.h"

#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace llvm;
using namespace std;

namespace
{

class ASCR : public ModulePass
{
  class Visitor : public InstVisitor<Visitor> {
    public:
    Constant *randFunction;
    Visitor(Constant *randFunc) : randFunction(randFunc) {}

    void visitLoadInst(LoadInst& i) {
      // Replace with a *call* to rand function.
      BasicBlock::iterator ii(i);
      CallInst *ci = CallInst::Create(randFunction);
      ReplaceInstWithInst(i.getParent()->getInstList(), ii, ci);
    }
    void visitStoreInst(StoreInst& i) {
      // Delete store instructions, as they are unnecessary.
      BasicBlock::iterator ii(i);
      ReplaceInstWithValue(i.getParent()->getInstList(), ii,
        UndefValue::get(i.getType()));
    }
  };

  // Boilerplate for a basic block pass.
  public:
  static char ID;

  ASCR() :
    ModulePass(ID)
  {
  }

  ~ASCR()
  {
  }

  virtual bool runOnModule(Module &M) {
    Constant *randFunction = M.getOrInsertFunction("rand",
      FunctionType::get(Type::getInt32Ty(M.getContext()), false));

    // Run the above code on all of the instructions.
    Visitor d(randFunction);
    d.visit(M);
    return true;
  }
};

char ASCR::ID = 0;
RegisterPass<ASCR> X("ascr-dyn", "Address Space Content Randomization");
}
