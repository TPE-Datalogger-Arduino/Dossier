all: Dossier.pdf clean

Dossier.pdf: Dossier.tex
	pdflatex -interaction=nonstopmode -shell-escape Dossier.tex
	bibtex Dossier
	pdflatex -interaction=nonstopmode -shell-escape Dossier.tex

clean:
	rm -f *.log *.out *.aux *.toc *.lof *.lot *.bcf *.run.xml *-blx.bib *.blg *.bbl *.cpt *.backup
	rm -R _minted-*
