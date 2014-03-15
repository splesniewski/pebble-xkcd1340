pebble-xkcd1340
===============

Inspired by https://github.com/hausen/xkcd-clock here's my Pebble twist on it.

===============
## Requirements
- ImageMagick
- fontforge + python-fontforge
- PebbleSDK 2.0

## Build Instructions
- Clone this repository into ~/pebble-dev/
- Change to resource/ and run `make`.  This will pull download all the external dependencies and generate what need to generated.
- Run `pebble build`

## TODOs
- Improve image quality. The text looks a bit muddy.
- The time is really small.  Not really something you could glance at.

===============
Credits
-------
XKCD is the brainchild of [Randall Munroe](https://xkcd.com/about/), and all rights to the name "xkcd" belong to him. I am just a fan of his comics, and not affiliated with him in any way.
