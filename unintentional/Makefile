.PHONY: clean

unintentional.pdf: unintentional.tex citations.bib tableflip.pdf
	pdflatex $< && bibtex $(subst .tex,,$<) && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
