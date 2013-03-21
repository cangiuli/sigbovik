.PHONY: clean

unintentional.pdf: unintentional.tex citations.bib
#	pdflatex $<
	pdflatex $< && bibtex $(subst .tex,,$<) && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
