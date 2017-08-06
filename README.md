# pebble-xkcd1340
> Inspired by https://github.com/hausen/xkcd-clock here's my Pebble twist on it.

## Requirements
- ImageMagick
- Fontforge (w/ python scripting enabled)
- PebbleSDK 3+

## Build Instructions
- Clone this repository
- Install dependencies
    + MAC:
      * `brew install pebble`
      * `brew install imagemagick`
      * `brew install python gettext libpng jpeg libtiff giflib cairo libspiro czmq fontconfig automake libtool pkg-config glib pango`
      * `brew install fontforge`
- Navigate to resource/ and run `make`.  This will pull download all the external dependencies and generate what need to generated.
- Run `pebble build`
- Optional:
    + Run on watch `pebble install --phone 192.168.0.104 --logs # check IP addr in Pebble App > Developer`
    + Display in emulator `pebble install --emulator diorite --logs`

## TODOs
- Improve image quality. The text looks a bit muddy.
- The time is really small.  Not really something you could glance at.

Credits
-------
XKCD is the brainchild of [Randall Munroe](https://xkcd.com/about/), and all rights to the name "xkcd" belong to him. I am just a fan of his comics, and not affiliated with him in any way.
