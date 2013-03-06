.PHONY: clean

rvcs.pdf: rvcs.tex citations.bib
	pdflatex $<
	#pdflatex $< && bibtex $(subst .tex,,$<) && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
