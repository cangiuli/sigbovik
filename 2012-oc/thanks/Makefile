.PHONY: clean

thanks.pdf: thanks.tex
	pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.nav *.snm *.toc *.out *.vrb
