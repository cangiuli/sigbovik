.PHONY: clean

combined.pdf: blue.pdf red.pdf slide.pdf
	pdflatex combined.tex

red.pdf: red.tex
	pdflatex $<

blue.pdf: blue.tex
	pdflatex $<

slide.pdf: slide.tex
	pdflatex $<

clean:
	-rm -f *.aux *.log *.out *.snm *.toc *.nav
