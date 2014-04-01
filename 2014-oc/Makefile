.PHONY: clean

sigbovik.pdf: sigbovik.tex
	pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.nav *.snm *.toc *.out *.vrb
