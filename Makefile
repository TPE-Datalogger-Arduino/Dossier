all: Dossier.pdf clean

Dossier.pdf: Dossier.tex
	pdflatex -interaction=nonstopmode -shell-escape Dossier.tex
	bibtex Dossier
	pdflatex -interaction=nonstopmode -shell-escape Dossier.tex

clean:
	rm -f Dossier.log Dossier.out Dossier.aux Dossier.toc Dossier.lof Dossier.pyg Dossier.run.xml Dossier-blx.bib Dossier.blg Dossier.bbl *.backup
