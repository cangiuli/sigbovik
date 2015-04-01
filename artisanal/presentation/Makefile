.PHONY: clean

artisanal.pdf: artisanal.tex
	pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.nav *.snm *.toc *.out *.vrb
