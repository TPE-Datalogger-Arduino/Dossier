all: Dossier.pdf clean

Dossier.pdf: Dossier.tex
	pdflatex -interaction=nonstopmode -shell-escape Dossier.tex
	bibtex Dossier
	pdflatex -interaction=nonstopmode -shell-escape Dossier.tex

clean:
	rm -f Dossier.log Dossier.out Dossier.aux Dossier.toc Dossier.lof Dossier.pyg *.backup
