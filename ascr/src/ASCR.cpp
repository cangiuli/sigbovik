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

class ASCR : public BasicBlockPass
{
  class Visitor : public InstVisitor<Visitor> {
    public:
    void visitLoadInst(LoadInst& i) {
      // Statically replace with a random number.
      BasicBlock::iterator ii(i);
      ReplaceInstWithValue(i.getParent()->getInstList(), ii, 
        ConstantInt::get(i.getType(), rand()));
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
    BasicBlockPass(ID)
  {
  }

  ~ASCR()
  {
  }

  virtual bool runOnBasicBlock(BasicBlock &B) {
    // Run the above code on all of the instructions.
    Visitor d;
    d.visit(B);
    return true;
  }
};

char ASCR::ID = 0;
RegisterPass<ASCR> X("ascr", "Address Space Content Randomization");
}
