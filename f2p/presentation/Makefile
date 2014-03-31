.PHONY: clean

f2p.pdf: f2p.tex
	pdflatex $< && pdflatex $< 

clean:
	-rm -f *.aux *.log *.nav *.snm *.toc *.out *.vrb
