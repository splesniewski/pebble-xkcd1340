#include <pebble.h>

static Window *window;
static TextLayer *time_textlayer;

static GBitmap *xkcd1340_image;
static BitmapLayer *xkcd1340_layer;

static GFont xkcd_font;

static void update_time (struct tm *t){
  static char time_str[] = "CCyy-mm-dd HH:MM:SS !";

  if (clock_is_24h_style()) {
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S !", t);
  }else{
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %I:%M:%S !", t);
  }
  text_layer_set_text(time_textlayer, time_str);
}

void handle_second_tick(struct tm *t, TimeUnits units_changed) {
  update_time(t);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);

  //----------------
  xkcd1340_image=gbitmap_create_with_resource(RESOURCE_ID_XKCD1340);
  xkcd1340_layer=bitmap_layer_create(window_bounds);

  bitmap_layer_set_bitmap(xkcd1340_layer, xkcd1340_image);
  layer_add_child(window_layer, bitmap_layer_get_layer(xkcd1340_layer));

  //----------------
  time_textlayer = text_layer_create((GRect) { .origin = { 0, 15 }, .size = { window_bounds.size.w, 16 } });
  text_layer_set_text_alignment(time_textlayer, GTextAlignmentCenter);
  text_layer_set_background_color(time_textlayer, GColorClear);
  xkcd_font=fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_XKCD_8));
  text_layer_set_font(time_textlayer,xkcd_font);

  layer_add_child(window_layer, text_layer_get_layer(time_textlayer));

  time_t now= time(NULL);
  struct tm *t; 
  t = localtime(&now);
  update_time(t);

  //----------------
  tick_timer_service_subscribe(SECOND_UNIT, handle_second_tick);
}

static void window_unload(Window *window) {
  tick_timer_service_unsubscribe();

  text_layer_destroy(time_textlayer);
  fonts_unload_custom_font(xkcd_font);

  bitmap_layer_destroy(xkcd1340_layer);
  gbitmap_destroy(xkcd1340_image);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
