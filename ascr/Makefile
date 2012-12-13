.PHONY: clean

ascr.pdf: ascr.tex citations.bib
	pdflatex $< && bibtex ascr && pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.bbl *.blg *.out
