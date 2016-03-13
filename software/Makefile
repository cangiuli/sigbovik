.PHONY: clean

software.pdf: software.tex
	pdflatex $<
#	pdflatex $< && bibtex $(subst .tex,,$<) && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
