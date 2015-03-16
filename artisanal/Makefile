.PHONY: clean

artisanal.pdf: artisanal.tex artisanal.bib
#	pdflatex $<
	pdflatex $< && bibtex $(subst .tex,,$<) && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
