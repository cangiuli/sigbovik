.PHONY: clean

artisanal.pdf: artisanal.tex
	pdflatex $<
#	pdflatex $< && bibtex $(subst .tex,,$<) && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
