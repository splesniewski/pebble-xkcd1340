#
#
#
FILES=\
	font/xkcd.ttf \
	image/pebble.unique_time.png \
	image/menu.png

all: $(FILES)

clean:
	-rm -f *~ $(FILES)
	-rm -f _external/git/xkcd-font/build/xkcd.otf
	-rm -r image/clean.unique_time.png

veryclean: clean
	-rm -rf _external

#----------------------------------------------------------------
_external/xkcd/unique_date.png:
	-mkdir -p _external/xkcd/
	cd _external/xkcd && wget http://imgs.xkcd.com/comics/unique_date.png

#----------------------------------------------------------------
_external/git/xkcd-font/build.py:
	-mkdir -p _external/git/
	git clone https://github.com/ipython/xkcd-font.git _external/git/xkcd-font
	cd _external/git/xkcd-font/ && git gc --aggressive

_external/git/xkcd-font/build/xkcd.otf: _external/git/xkcd-font/build.py
	cd _external/git/xkcd-font/ && python build.py

#----------------------------------------------------------------
font/xkcd.ttf:bin/otf2ttf.pe _external/git/xkcd-font/build/xkcd.otf
	-mkdir font/
	/usr/bin/fontforge -script bin/otf2ttf.pe _external/git/xkcd-font/build/xkcd.otf $@

#----------------------------------------------------------------
image/clean.unique_time.png: _external/xkcd/unique_date.png
	-mkdir image/
	convert $< \
	-fill white \
	-draw 'rectangle 2,32 180,48' \
	$@

image/pebble.unique_time.png: image/clean.unique_time.png
	convert $< \
	-resize 144x168 \
	-threshold 56% \
	$@
	identify $@

image/menu.png: font/xkcd.ttf
	echo "x" \
	| convert -font font/xkcd.ttf -background white -pointsize $$((6 * 72)) -trim +repage label:@-  \
	-resize 24x28 \
	-threshold 50% \
	$@
	identify $@
