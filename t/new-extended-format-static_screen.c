#include <unibilium.h>
#include <errno.h>
#include <string.h>
#include "test-simple.c.inc"

static const char terminfo[] = {
    26, 1, 42, 0, 43, 0, 15, 0, 105, 1, -103, 2, 115, 99, 114, 101, 101, 110, 124, 86,
    84, 32, 49, 48, 48, 47, 65, 78, 83, 73, 32, 88, 51, 46, 54, 52, 32, 118, 105, 114,
    116, 117, 97, 108, 32, 116, 101, 114, 109, 105, 110, 97, 108, 0, 0, 1, 0, 0, 1, 0,
    0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 80, 0,
    8, 0, 24, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 8, 0, 64, 0, 0, 0, 4, 0, 6, 0, 8, 0, 25, 0, 30, 0,
    37, 0, 41, 0, 45, 0, -1, -1, 56, 0, 73, 0, 75, 0, 79, 0, 86, 0, -1, -1,
    88, 0, 100, 0, -1, -1, 104, 0, 107, 0, 113, 0, 117, 0, -1, -1, -1, -1, 121, 0,
    123, 0, -128, 0, -123, 0, -1, -1, -114, 0, -109, 0, -1, -1, -1, -1, -104, 0, -99, 0,
    -94, 0, -1, -1, -89, 0, -87, 0, -82, 0, -1, -1, -73, 0, -68, 0, -62, 0, -56, 0,
    -1, -1, -1, -1, -1, -1, -53, 0, -1, -1, -1, -1, -1, -1, -49, 0, -1, -1, -45, 0,
    -1, -1, -1, -1, -1, -1, -43, 0, -1, -1, -38, 0, -1, -1, -1, -1, -1, -1, -1, -1,
    -34, 0, -30, 0, -24, 0, -20, 0, -16, 0, -12, 0, -6, 0, 0, 1, 6, 1, 12, 1,
    18, 1, 23, 1, -1, -1, 28, 1, -1, -1, 32, 1, 37, 1, 42, 1, -1, -1, -1, -1,
    -1, -1, 46, 1, 50, 1, 58, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 66, 1, -1, -1, 69, 1,
    78, 1, 87, 1, 96, 1, 105, 1, 114, 1, 123, 1, -124, 1, -1, -1, -115, 1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -106, 1, -1, -1, -1, -1,
    -89, 1, -86, 1, -75, 1, -72, 1, -70, 1, -67, 1, 17, 2, -1, -1, 20, 2, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    22, 2, -1, -1, 87, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 91, 2,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 98, 2, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    103, 2, 109, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, 115, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 120, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -127, 2,
    -1, -1, -1, -1, -1, -1, -123, 2, -113, 2, 27, 91, 90, 0, 7, 0, 13, 0, 27, 91,
    37, 105, 37, 112, 49, 37, 100, 59, 37, 112, 50, 37, 100, 114, 0, 27, 91, 51, 103, 0,
    27, 91, 72, 27, 91, 74, 0, 27, 91, 75, 0, 27, 91, 74, 0, 27, 91, 37, 105, 37,
    112, 49, 37, 100, 71, 0, 27, 91, 37, 105, 37, 112, 49, 37, 100, 59, 37, 112, 50, 37,
    100, 72, 0, 10, 0, 27, 91, 72, 0, 27, 91, 63, 50, 53, 108, 0, 8, 0, 27, 91,
    51, 52, 104, 27, 91, 63, 50, 53, 104, 0, 27, 91, 67, 0, 27, 77, 0, 27, 91, 51,
    52, 108, 0, 27, 91, 80, 0, 27, 91, 77, 0, 14, 0, 27, 91, 53, 109, 0, 27, 91,
    49, 109, 0, 27, 91, 63, 49, 48, 52, 57, 104, 0, 27, 91, 50, 109, 0, 27, 91, 52,
    104, 0, 27, 91, 55, 109, 0, 27, 91, 51, 109, 0, 27, 91, 52, 109, 0, 15, 0, 27,
    91, 109, 15, 0, 27, 91, 63, 49, 48, 52, 57, 108, 0, 27, 91, 52, 108, 0, 27, 91,
    50, 51, 109, 0, 27, 91, 50, 52, 109, 0, 27, 103, 0, 27, 41, 48, 0, 27, 91, 76,
    0, 127, 0, 27, 91, 51, 126, 0, 27, 79, 66, 0, 27, 79, 80, 0, 27, 91, 50, 49,
    126, 0, 27, 79, 81, 0, 27, 79, 82, 0, 27, 79, 83, 0, 27, 91, 49, 53, 126, 0,
    27, 91, 49, 55, 126, 0, 27, 91, 49, 56, 126, 0, 27, 91, 49, 57, 126, 0, 27, 91,
    50, 48, 126, 0, 27, 91, 49, 126, 0, 27, 91, 50, 126, 0, 27, 79, 68, 0, 27, 91,
    54, 126, 0, 27, 91, 53, 126, 0, 27, 79, 67, 0, 27, 79, 65, 0, 27, 91, 63, 49,
    108, 27, 62, 0, 27, 91, 63, 49, 104, 27, 61, 0, 27, 69, 0, 27, 91, 37, 112, 49,
    37, 100, 80, 0, 27, 91, 37, 112, 49, 37, 100, 77, 0, 27, 91, 37, 112, 49, 37, 100,
    66, 0, 27, 91, 37, 112, 49, 37, 100, 64, 0, 27, 91, 37, 112, 49, 37, 100, 83, 0,
    27, 91, 37, 112, 49, 37, 100, 76, 0, 27, 91, 37, 112, 49, 37, 100, 68, 0, 27, 91,
    37, 112, 49, 37, 100, 67, 0, 27, 91, 37, 112, 49, 37, 100, 65, 0, 27, 99, 27, 91,
    63, 49, 48, 48, 48, 108, 27, 91, 63, 50, 53, 104, 0, 27, 56, 0, 27, 91, 37, 105,
    37, 112, 49, 37, 100, 100, 0, 27, 55, 0, 10, 0, 27, 77, 0, 27, 91, 48, 37, 63,
    37, 112, 54, 37, 116, 59, 49, 37, 59, 37, 63, 37, 112, 49, 37, 116, 59, 51, 37, 59,
    37, 63, 37, 112, 50, 37, 116, 59, 52, 37, 59, 37, 63, 37, 112, 51, 37, 116, 59, 55,
    37, 59, 37, 63, 37, 112, 52, 37, 116, 59, 53, 37, 59, 37, 63, 37, 112, 53, 37, 116,
    59, 50, 37, 59, 109, 37, 63, 37, 112, 57, 37, 116, 14, 37, 101, 15, 37, 59, 0, 27,
    72, 0, 9, 0, 43, 43, 44, 44, 45, 45, 46, 46, 48, 48, 96, 96, 97, 97, 102, 102,
    103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112,
    113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122,
    123, 123, 124, 124, 125, 125, 126, 126, 0, 27, 91, 90, 0, 27, 40, 66, 27, 41, 48, 0,
    27, 91, 52, 126, 0, 27, 91, 50, 51, 126, 0, 27, 91, 50, 52, 126, 0, 27, 91, 49,
    75, 0, 27, 91, 51, 57, 59, 52, 57, 109, 0, 27, 91, 77, 0, 27, 91, 51, 37, 112,
    49, 37, 100, 109, 0, 27, 91, 52, 37, 112, 49, 37, 100, 109, 0, 0, 3, 0, 1, 0,
    12, 0, 28, 0, 70, 0, 1, 1, 0, 0, 1, 0, 0, 0, -1, -1, 4, 0, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 3, 0,
    6, 0, 9, 0, 12, 0, 15, 0, 18, 0, 21, 0, 24, 0, 27, 0, 33, 0, 39, 0,
    43, 0, 47, 0, 51, 0, 55, 0, 27, 40, 66, 0, 27, 40, 37, 112, 49, 37, 99, 0,
    65, 88, 0, 71, 48, 0, 88, 84, 0, 85, 56, 0, 69, 48, 0, 69, 51, 0, 83, 48,
    0, 84, 83, 0, 88, 77, 0, 107, 69, 78, 68, 53, 0, 107, 72, 79, 77, 53, 0, 107,
    97, 50, 0, 107, 98, 49, 0, 107, 98, 51, 0, 107, 99, 50, 0, 120, 109, 0
};

static void setup(void);

int main(void) {
    int e;
    unibi_term *dt;

    setup();

    dt = unibi_dummy();
    e = errno;
    ok(dt != NULL, "dummy constructed");
    if (!dt) {
        bail_out(strerror(e));
    }
    unibi_term *ut = unibi_from_mem(terminfo, sizeof terminfo);
    e = errno;
    ok(ut != NULL, "terminfo loaded");
    if (!ut) {
        bail_out(strerror(e));
    }

    note("terminal name");
    ok(strcmp(unibi_get_name(ut), "VT 100/ANSI X3.64 virtual terminal") == 0, "terminal name = \"%s\"", "VT 100/ANSI X3.64 virtual terminal");
    unibi_set_name(dt, "VT 100/ANSI X3.64 virtual terminal");
    {
        static const char *def_aliases[] = {"screen", NULL};
        const char **aliases = unibi_get_aliases(ut);
        ok(strcmp(aliases[0], def_aliases[0]) == 0, "terminal alias #0 = \"%s\"", "screen");
        ok(aliases[1] == NULL, "terminal alias #1 = null");
        unibi_set_aliases(dt, def_aliases);
    }

    note("boolean capabilities");
    ok(unibi_get_bool(ut, unibi_auto_left_margin) == 0, "auto_left_margin = false");
    ok(unibi_get_bool(ut, unibi_auto_right_margin) == 1, "auto_right_margin = true");
    unibi_set_bool(dt, unibi_auto_right_margin, 1);
    ok(unibi_get_bool(ut, unibi_no_esc_ctlc) == 0, "no_esc_ctlc = false");
    ok(unibi_get_bool(ut, unibi_ceol_standout_glitch) == 0, "ceol_standout_glitch = false");
    ok(unibi_get_bool(ut, unibi_eat_newline_glitch) == 1, "eat_newline_glitch = true");
    unibi_set_bool(dt, unibi_eat_newline_glitch, 1);
    ok(unibi_get_bool(ut, unibi_erase_overstrike) == 0, "erase_overstrike = false");
    ok(unibi_get_bool(ut, unibi_generic_type) == 0, "generic_type = false");
    ok(unibi_get_bool(ut, unibi_hard_copy) == 0, "hard_copy = false");
    ok(unibi_get_bool(ut, unibi_has_meta_key) == 1, "has_meta_key = true");
    unibi_set_bool(dt, unibi_has_meta_key, 1);
    ok(unibi_get_bool(ut, unibi_has_status_line) == 0, "has_status_line = false");
    ok(unibi_get_bool(ut, unibi_insert_null_glitch) == 0, "insert_null_glitch = false");
    ok(unibi_get_bool(ut, unibi_memory_above) == 0, "memory_above = false");
    ok(unibi_get_bool(ut, unibi_memory_below) == 0, "memory_below = false");
    ok(unibi_get_bool(ut, unibi_move_insert_mode) == 1, "move_insert_mode = true");
    unibi_set_bool(dt, unibi_move_insert_mode, 1);
    ok(unibi_get_bool(ut, unibi_move_standout_mode) == 1, "move_standout_mode = true");
    unibi_set_bool(dt, unibi_move_standout_mode, 1);
    ok(unibi_get_bool(ut, unibi_over_strike) == 0, "over_strike = false");
    ok(unibi_get_bool(ut, unibi_status_line_esc_ok) == 0, "status_line_esc_ok = false");
    ok(unibi_get_bool(ut, unibi_dest_tabs_magic_smso) == 0, "dest_tabs_magic_smso = false");
    ok(unibi_get_bool(ut, unibi_tilde_glitch) == 0, "tilde_glitch = false");
    ok(unibi_get_bool(ut, unibi_transparent_underline) == 0, "transparent_underline = false");
    ok(unibi_get_bool(ut, unibi_xon_xoff) == 0, "xon_xoff = false");
    ok(unibi_get_bool(ut, unibi_needs_xon_xoff) == 0, "needs_xon_xoff = false");
    ok(unibi_get_bool(ut, unibi_prtr_silent) == 0, "prtr_silent = false");
    ok(unibi_get_bool(ut, unibi_hard_cursor) == 0, "hard_cursor = false");
    ok(unibi_get_bool(ut, unibi_non_rev_rmcup) == 0, "non_rev_rmcup = false");
    ok(unibi_get_bool(ut, unibi_no_pad_char) == 0, "no_pad_char = false");
    ok(unibi_get_bool(ut, unibi_non_dest_scroll_region) == 0, "non_dest_scroll_region = false");
    ok(unibi_get_bool(ut, unibi_can_change) == 0, "can_change = false");
    ok(unibi_get_bool(ut, unibi_back_color_erase) == 0, "back_color_erase = false");
    ok(unibi_get_bool(ut, unibi_hue_lightness_saturation) == 0, "hue_lightness_saturation = false");
    ok(unibi_get_bool(ut, unibi_col_addr_glitch) == 0, "col_addr_glitch = false");
    ok(unibi_get_bool(ut, unibi_cr_cancels_micro_mode) == 0, "cr_cancels_micro_mode = false");
    ok(unibi_get_bool(ut, unibi_has_print_wheel) == 0, "has_print_wheel = false");
    ok(unibi_get_bool(ut, unibi_row_addr_glitch) == 0, "row_addr_glitch = false");
    ok(unibi_get_bool(ut, unibi_semi_auto_right_margin) == 0, "semi_auto_right_margin = false");
    ok(unibi_get_bool(ut, unibi_cpi_changes_res) == 0, "cpi_changes_res = false");
    ok(unibi_get_bool(ut, unibi_lpi_changes_res) == 0, "lpi_changes_res = false");
    ok(unibi_get_bool(ut, unibi_backspaces_with_bs) == 1, "backspaces_with_bs = true");
    unibi_set_bool(dt, unibi_backspaces_with_bs, 1);
    ok(unibi_get_bool(ut, unibi_crt_no_scrolling) == 0, "crt_no_scrolling = false");
    ok(unibi_get_bool(ut, unibi_no_correctly_working_cr) == 0, "no_correctly_working_cr = false");
    ok(unibi_get_bool(ut, unibi_gnu_has_meta_key) == 0, "gnu_has_meta_key = false");
    ok(unibi_get_bool(ut, unibi_linefeed_is_newline) == 0, "linefeed_is_newline = false");
    ok(unibi_get_bool(ut, unibi_has_hardware_tabs) == 1, "has_hardware_tabs = true");
    unibi_set_bool(dt, unibi_has_hardware_tabs, 1);
    ok(unibi_get_bool(ut, unibi_return_does_clr_eol) == 0, "return_does_clr_eol = false");

    note("numeric capabilities");
    ok(unibi_get_num(ut, unibi_columns) == 80, "columns = 80");
    unibi_set_num(dt, unibi_columns, 80);
    ok(unibi_get_num(ut, unibi_init_tabs) == 8, "init_tabs = 8");
    unibi_set_num(dt, unibi_init_tabs, 8);
    ok(unibi_get_num(ut, unibi_lines) == 24, "lines = 24");
    unibi_set_num(dt, unibi_lines, 24);
    ok(unibi_get_num(ut, unibi_lines_of_memory) == -1, "lines_of_memory = -1");
    ok(unibi_get_num(ut, unibi_magic_cookie_glitch) == -1, "magic_cookie_glitch = -1");
    ok(unibi_get_num(ut, unibi_padding_baud_rate) == -1, "padding_baud_rate = -1");
    ok(unibi_get_num(ut, unibi_virtual_terminal) == -1, "virtual_terminal = -1");
    ok(unibi_get_num(ut, unibi_width_status_line) == -1, "width_status_line = -1");
    ok(unibi_get_num(ut, unibi_num_labels) == -1, "num_labels = -1");
    ok(unibi_get_num(ut, unibi_label_height) == -1, "label_height = -1");
    ok(unibi_get_num(ut, unibi_label_width) == -1, "label_width = -1");
    ok(unibi_get_num(ut, unibi_max_attributes) == -1, "max_attributes = -1");
    ok(unibi_get_num(ut, unibi_maximum_windows) == -1, "maximum_windows = -1");
    ok(unibi_get_num(ut, unibi_max_colors) == 8, "max_colors = 8");
    unibi_set_num(dt, unibi_max_colors, 8);
    ok(unibi_get_num(ut, unibi_max_pairs) == 64, "max_pairs = 64");
    unibi_set_num(dt, unibi_max_pairs, 64);
    ok(unibi_get_num(ut, unibi_no_color_video) == -1, "no_color_video = -1");
    ok(unibi_get_num(ut, unibi_buffer_capacity) == -1, "buffer_capacity = -1");
    ok(unibi_get_num(ut, unibi_dot_vert_spacing) == -1, "dot_vert_spacing = -1");
    ok(unibi_get_num(ut, unibi_dot_horz_spacing) == -1, "dot_horz_spacing = -1");
    ok(unibi_get_num(ut, unibi_max_micro_address) == -1, "max_micro_address = -1");
    ok(unibi_get_num(ut, unibi_max_micro_jump) == -1, "max_micro_jump = -1");
    ok(unibi_get_num(ut, unibi_micro_col_size) == -1, "micro_col_size = -1");
    ok(unibi_get_num(ut, unibi_micro_line_size) == -1, "micro_line_size = -1");
    ok(unibi_get_num(ut, unibi_number_of_pins) == -1, "number_of_pins = -1");
    ok(unibi_get_num(ut, unibi_output_res_char) == -1, "output_res_char = -1");
    ok(unibi_get_num(ut, unibi_output_res_line) == -1, "output_res_line = -1");
    ok(unibi_get_num(ut, unibi_output_res_horz_inch) == -1, "output_res_horz_inch = -1");
    ok(unibi_get_num(ut, unibi_output_res_vert_inch) == -1, "output_res_vert_inch = -1");
    ok(unibi_get_num(ut, unibi_print_rate) == -1, "print_rate = -1");
    ok(unibi_get_num(ut, unibi_wide_char_size) == -1, "wide_char_size = -1");
    ok(unibi_get_num(ut, unibi_buttons) == -1, "buttons = -1");
    ok(unibi_get_num(ut, unibi_bit_image_entwining) == -1, "bit_image_entwining = -1");
    ok(unibi_get_num(ut, unibi_bit_image_type) == -1, "bit_image_type = -1");
    ok(unibi_get_num(ut, unibi_magic_cookie_glitch_ul) == -1, "magic_cookie_glitch_ul = -1");
    ok(unibi_get_num(ut, unibi_carriage_return_delay) == -1, "carriage_return_delay = -1");
    ok(unibi_get_num(ut, unibi_new_line_delay) == -1, "new_line_delay = -1");
    ok(unibi_get_num(ut, unibi_backspace_delay) == -1, "backspace_delay = -1");
    ok(unibi_get_num(ut, unibi_horizontal_tab_delay) == -1, "horizontal_tab_delay = -1");
    ok(unibi_get_num(ut, unibi_number_of_function_keys) == -1, "number_of_function_keys = -1");

    note("string capabilities");
    ok(strcmp(unibi_get_str(ut, unibi_back_tab), "\033[Z") == 0, "back_tab = \"%s\"", "\\033[Z");
    unibi_set_str(dt, unibi_back_tab, "\033[Z");
    ok(strcmp(unibi_get_str(ut, unibi_bell), "\007") == 0, "bell = \"%s\"", "\\007");
    unibi_set_str(dt, unibi_bell, "\007");
    ok(strcmp(unibi_get_str(ut, unibi_carriage_return), "\015") == 0, "carriage_return = \"%s\"", "\\015");
    unibi_set_str(dt, unibi_carriage_return, "\015");
    ok(strcmp(unibi_get_str(ut, unibi_change_scroll_region), "\033[%i%p1%d;%p2%dr") == 0, "change_scroll_region = \"%s\"", "\\033[%i%p1%d;%p2%dr");
    unibi_set_str(dt, unibi_change_scroll_region, "\033[%i%p1%d;%p2%dr");
    ok(strcmp(unibi_get_str(ut, unibi_clear_all_tabs), "\033[3g") == 0, "clear_all_tabs = \"%s\"", "\\033[3g");
    unibi_set_str(dt, unibi_clear_all_tabs, "\033[3g");
    ok(strcmp(unibi_get_str(ut, unibi_clear_screen), "\033[H\033[J") == 0, "clear_screen = \"%s\"", "\\033[H\\033[J");
    unibi_set_str(dt, unibi_clear_screen, "\033[H\033[J");
    ok(strcmp(unibi_get_str(ut, unibi_clr_eol), "\033[K") == 0, "clr_eol = \"%s\"", "\\033[K");
    unibi_set_str(dt, unibi_clr_eol, "\033[K");
    ok(strcmp(unibi_get_str(ut, unibi_clr_eos), "\033[J") == 0, "clr_eos = \"%s\"", "\\033[J");
    unibi_set_str(dt, unibi_clr_eos, "\033[J");
    ok(strcmp(unibi_get_str(ut, unibi_column_address), "\033[%i%p1%dG") == 0, "column_address = \"%s\"", "\\033[%i%p1%dG");
    unibi_set_str(dt, unibi_column_address, "\033[%i%p1%dG");
    ok(unibi_get_str(ut, unibi_command_character) == NULL, "command_character = null");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_address), "\033[%i%p1%d;%p2%dH") == 0, "cursor_address = \"%s\"", "\\033[%i%p1%d;%p2%dH");
    unibi_set_str(dt, unibi_cursor_address, "\033[%i%p1%d;%p2%dH");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_down), "\012") == 0, "cursor_down = \"%s\"", "\\012");
    unibi_set_str(dt, unibi_cursor_down, "\012");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_home), "\033[H") == 0, "cursor_home = \"%s\"", "\\033[H");
    unibi_set_str(dt, unibi_cursor_home, "\033[H");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_invisible), "\033[?25l") == 0, "cursor_invisible = \"%s\"", "\\033[?25l");
    unibi_set_str(dt, unibi_cursor_invisible, "\033[?25l");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_left), "\010") == 0, "cursor_left = \"%s\"", "\\010");
    unibi_set_str(dt, unibi_cursor_left, "\010");
    ok(unibi_get_str(ut, unibi_cursor_mem_address) == NULL, "cursor_mem_address = null");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_normal), "\033[34h\033[?25h") == 0, "cursor_normal = \"%s\"", "\\033[34h\\033[?25h");
    unibi_set_str(dt, unibi_cursor_normal, "\033[34h\033[?25h");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_right), "\033[C") == 0, "cursor_right = \"%s\"", "\\033[C");
    unibi_set_str(dt, unibi_cursor_right, "\033[C");
    ok(unibi_get_str(ut, unibi_cursor_to_ll) == NULL, "cursor_to_ll = null");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_up), "\033M") == 0, "cursor_up = \"%s\"", "\\033M");
    unibi_set_str(dt, unibi_cursor_up, "\033M");
    ok(strcmp(unibi_get_str(ut, unibi_cursor_visible), "\033[34l") == 0, "cursor_visible = \"%s\"", "\\033[34l");
    unibi_set_str(dt, unibi_cursor_visible, "\033[34l");
    ok(strcmp(unibi_get_str(ut, unibi_delete_character), "\033[P") == 0, "delete_character = \"%s\"", "\\033[P");
    unibi_set_str(dt, unibi_delete_character, "\033[P");
    ok(strcmp(unibi_get_str(ut, unibi_delete_line), "\033[M") == 0, "delete_line = \"%s\"", "\\033[M");
    unibi_set_str(dt, unibi_delete_line, "\033[M");
    ok(unibi_get_str(ut, unibi_dis_status_line) == NULL, "dis_status_line = null");
    ok(unibi_get_str(ut, unibi_down_half_line) == NULL, "down_half_line = null");
    ok(strcmp(unibi_get_str(ut, unibi_enter_alt_charset_mode), "\016") == 0, "enter_alt_charset_mode = \"%s\"", "\\016");
    unibi_set_str(dt, unibi_enter_alt_charset_mode, "\016");
    ok(strcmp(unibi_get_str(ut, unibi_enter_blink_mode), "\033[5m") == 0, "enter_blink_mode = \"%s\"", "\\033[5m");
    unibi_set_str(dt, unibi_enter_blink_mode, "\033[5m");
    ok(strcmp(unibi_get_str(ut, unibi_enter_bold_mode), "\033[1m") == 0, "enter_bold_mode = \"%s\"", "\\033[1m");
    unibi_set_str(dt, unibi_enter_bold_mode, "\033[1m");
    ok(strcmp(unibi_get_str(ut, unibi_enter_ca_mode), "\033[?1049h") == 0, "enter_ca_mode = \"%s\"", "\\033[?1049h");
    unibi_set_str(dt, unibi_enter_ca_mode, "\033[?1049h");
    ok(unibi_get_str(ut, unibi_enter_delete_mode) == NULL, "enter_delete_mode = null");
    ok(strcmp(unibi_get_str(ut, unibi_enter_dim_mode), "\033[2m") == 0, "enter_dim_mode = \"%s\"", "\\033[2m");
    unibi_set_str(dt, unibi_enter_dim_mode, "\033[2m");
    ok(strcmp(unibi_get_str(ut, unibi_enter_insert_mode), "\033[4h") == 0, "enter_insert_mode = \"%s\"", "\\033[4h");
    unibi_set_str(dt, unibi_enter_insert_mode, "\033[4h");
    ok(unibi_get_str(ut, unibi_enter_secure_mode) == NULL, "enter_secure_mode = null");
    ok(unibi_get_str(ut, unibi_enter_protected_mode) == NULL, "enter_protected_mode = null");
    ok(strcmp(unibi_get_str(ut, unibi_enter_reverse_mode), "\033[7m") == 0, "enter_reverse_mode = \"%s\"", "\\033[7m");
    unibi_set_str(dt, unibi_enter_reverse_mode, "\033[7m");
    ok(strcmp(unibi_get_str(ut, unibi_enter_standout_mode), "\033[3m") == 0, "enter_standout_mode = \"%s\"", "\\033[3m");
    unibi_set_str(dt, unibi_enter_standout_mode, "\033[3m");
    ok(strcmp(unibi_get_str(ut, unibi_enter_underline_mode), "\033[4m") == 0, "enter_underline_mode = \"%s\"", "\\033[4m");
    unibi_set_str(dt, unibi_enter_underline_mode, "\033[4m");
    ok(unibi_get_str(ut, unibi_erase_chars) == NULL, "erase_chars = null");
    ok(strcmp(unibi_get_str(ut, unibi_exit_alt_charset_mode), "\017") == 0, "exit_alt_charset_mode = \"%s\"", "\\017");
    unibi_set_str(dt, unibi_exit_alt_charset_mode, "\017");
    ok(strcmp(unibi_get_str(ut, unibi_exit_attribute_mode), "\033[m\017") == 0, "exit_attribute_mode = \"%s\"", "\\033[m\\017");
    unibi_set_str(dt, unibi_exit_attribute_mode, "\033[m\017");
    ok(strcmp(unibi_get_str(ut, unibi_exit_ca_mode), "\033[?1049l") == 0, "exit_ca_mode = \"%s\"", "\\033[?1049l");
    unibi_set_str(dt, unibi_exit_ca_mode, "\033[?1049l");
    ok(unibi_get_str(ut, unibi_exit_delete_mode) == NULL, "exit_delete_mode = null");
    ok(strcmp(unibi_get_str(ut, unibi_exit_insert_mode), "\033[4l") == 0, "exit_insert_mode = \"%s\"", "\\033[4l");
    unibi_set_str(dt, unibi_exit_insert_mode, "\033[4l");
    ok(strcmp(unibi_get_str(ut, unibi_exit_standout_mode), "\033[23m") == 0, "exit_standout_mode = \"%s\"", "\\033[23m");
    unibi_set_str(dt, unibi_exit_standout_mode, "\033[23m");
    ok(strcmp(unibi_get_str(ut, unibi_exit_underline_mode), "\033[24m") == 0, "exit_underline_mode = \"%s\"", "\\033[24m");
    unibi_set_str(dt, unibi_exit_underline_mode, "\033[24m");
    ok(strcmp(unibi_get_str(ut, unibi_flash_screen), "\033g") == 0, "flash_screen = \"%s\"", "\\033g");
    unibi_set_str(dt, unibi_flash_screen, "\033g");
    ok(unibi_get_str(ut, unibi_form_feed) == NULL, "form_feed = null");
    ok(unibi_get_str(ut, unibi_from_status_line) == NULL, "from_status_line = null");
    ok(unibi_get_str(ut, unibi_init_1string) == NULL, "init_1string = null");
    ok(strcmp(unibi_get_str(ut, unibi_init_2string), "\033)0") == 0, "init_2string = \"%s\"", "\\033)0");
    unibi_set_str(dt, unibi_init_2string, "\033)0");
    ok(unibi_get_str(ut, unibi_init_3string) == NULL, "init_3string = null");
    ok(unibi_get_str(ut, unibi_init_file) == NULL, "init_file = null");
    ok(unibi_get_str(ut, unibi_insert_character) == NULL, "insert_character = null");
    ok(strcmp(unibi_get_str(ut, unibi_insert_line), "\033[L") == 0, "insert_line = \"%s\"", "\\033[L");
    unibi_set_str(dt, unibi_insert_line, "\033[L");
    ok(unibi_get_str(ut, unibi_insert_padding) == NULL, "insert_padding = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_backspace), "\177") == 0, "key_backspace = \"%s\"", "\\177");
    unibi_set_str(dt, unibi_key_backspace, "\177");
    ok(unibi_get_str(ut, unibi_key_catab) == NULL, "key_catab = null");
    ok(unibi_get_str(ut, unibi_key_clear) == NULL, "key_clear = null");
    ok(unibi_get_str(ut, unibi_key_ctab) == NULL, "key_ctab = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_dc), "\033[3~") == 0, "key_dc = \"%s\"", "\\033[3~");
    unibi_set_str(dt, unibi_key_dc, "\033[3~");
    ok(unibi_get_str(ut, unibi_key_dl) == NULL, "key_dl = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_down), "\033OB") == 0, "key_down = \"%s\"", "\\033OB");
    unibi_set_str(dt, unibi_key_down, "\033OB");
    ok(unibi_get_str(ut, unibi_key_eic) == NULL, "key_eic = null");
    ok(unibi_get_str(ut, unibi_key_eol) == NULL, "key_eol = null");
    ok(unibi_get_str(ut, unibi_key_eos) == NULL, "key_eos = null");
    ok(unibi_get_str(ut, unibi_key_f0) == NULL, "key_f0 = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_f1), "\033OP") == 0, "key_f1 = \"%s\"", "\\033OP");
    unibi_set_str(dt, unibi_key_f1, "\033OP");
    ok(strcmp(unibi_get_str(ut, unibi_key_f10), "\033[21~") == 0, "key_f10 = \"%s\"", "\\033[21~");
    unibi_set_str(dt, unibi_key_f10, "\033[21~");
    ok(strcmp(unibi_get_str(ut, unibi_key_f2), "\033OQ") == 0, "key_f2 = \"%s\"", "\\033OQ");
    unibi_set_str(dt, unibi_key_f2, "\033OQ");
    ok(strcmp(unibi_get_str(ut, unibi_key_f3), "\033OR") == 0, "key_f3 = \"%s\"", "\\033OR");
    unibi_set_str(dt, unibi_key_f3, "\033OR");
    ok(strcmp(unibi_get_str(ut, unibi_key_f4), "\033OS") == 0, "key_f4 = \"%s\"", "\\033OS");
    unibi_set_str(dt, unibi_key_f4, "\033OS");
    ok(strcmp(unibi_get_str(ut, unibi_key_f5), "\033[15~") == 0, "key_f5 = \"%s\"", "\\033[15~");
    unibi_set_str(dt, unibi_key_f5, "\033[15~");
    ok(strcmp(unibi_get_str(ut, unibi_key_f6), "\033[17~") == 0, "key_f6 = \"%s\"", "\\033[17~");
    unibi_set_str(dt, unibi_key_f6, "\033[17~");
    ok(strcmp(unibi_get_str(ut, unibi_key_f7), "\033[18~") == 0, "key_f7 = \"%s\"", "\\033[18~");
    unibi_set_str(dt, unibi_key_f7, "\033[18~");
    ok(strcmp(unibi_get_str(ut, unibi_key_f8), "\033[19~") == 0, "key_f8 = \"%s\"", "\\033[19~");
    unibi_set_str(dt, unibi_key_f8, "\033[19~");
    ok(strcmp(unibi_get_str(ut, unibi_key_f9), "\033[20~") == 0, "key_f9 = \"%s\"", "\\033[20~");
    unibi_set_str(dt, unibi_key_f9, "\033[20~");
    ok(strcmp(unibi_get_str(ut, unibi_key_home), "\033[1~") == 0, "key_home = \"%s\"", "\\033[1~");
    unibi_set_str(dt, unibi_key_home, "\033[1~");
    ok(strcmp(unibi_get_str(ut, unibi_key_ic), "\033[2~") == 0, "key_ic = \"%s\"", "\\033[2~");
    unibi_set_str(dt, unibi_key_ic, "\033[2~");
    ok(unibi_get_str(ut, unibi_key_il) == NULL, "key_il = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_left), "\033OD") == 0, "key_left = \"%s\"", "\\033OD");
    unibi_set_str(dt, unibi_key_left, "\033OD");
    ok(unibi_get_str(ut, unibi_key_ll) == NULL, "key_ll = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_npage), "\033[6~") == 0, "key_npage = \"%s\"", "\\033[6~");
    unibi_set_str(dt, unibi_key_npage, "\033[6~");
    ok(strcmp(unibi_get_str(ut, unibi_key_ppage), "\033[5~") == 0, "key_ppage = \"%s\"", "\\033[5~");
    unibi_set_str(dt, unibi_key_ppage, "\033[5~");
    ok(strcmp(unibi_get_str(ut, unibi_key_right), "\033OC") == 0, "key_right = \"%s\"", "\\033OC");
    unibi_set_str(dt, unibi_key_right, "\033OC");
    ok(unibi_get_str(ut, unibi_key_sf) == NULL, "key_sf = null");
    ok(unibi_get_str(ut, unibi_key_sr) == NULL, "key_sr = null");
    ok(unibi_get_str(ut, unibi_key_stab) == NULL, "key_stab = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_up), "\033OA") == 0, "key_up = \"%s\"", "\\033OA");
    unibi_set_str(dt, unibi_key_up, "\033OA");
    ok(strcmp(unibi_get_str(ut, unibi_keypad_local), "\033[?1l\033>") == 0, "keypad_local = \"%s\"", "\\033[?1l\\033>");
    unibi_set_str(dt, unibi_keypad_local, "\033[?1l\033>");
    ok(strcmp(unibi_get_str(ut, unibi_keypad_xmit), "\033[?1h\033=") == 0, "keypad_xmit = \"%s\"", "\\033[?1h\\033=");
    unibi_set_str(dt, unibi_keypad_xmit, "\033[?1h\033=");
    ok(unibi_get_str(ut, unibi_lab_f0) == NULL, "lab_f0 = null");
    ok(unibi_get_str(ut, unibi_lab_f1) == NULL, "lab_f1 = null");
    ok(unibi_get_str(ut, unibi_lab_f10) == NULL, "lab_f10 = null");
    ok(unibi_get_str(ut, unibi_lab_f2) == NULL, "lab_f2 = null");
    ok(unibi_get_str(ut, unibi_lab_f3) == NULL, "lab_f3 = null");
    ok(unibi_get_str(ut, unibi_lab_f4) == NULL, "lab_f4 = null");
    ok(unibi_get_str(ut, unibi_lab_f5) == NULL, "lab_f5 = null");
    ok(unibi_get_str(ut, unibi_lab_f6) == NULL, "lab_f6 = null");
    ok(unibi_get_str(ut, unibi_lab_f7) == NULL, "lab_f7 = null");
    ok(unibi_get_str(ut, unibi_lab_f8) == NULL, "lab_f8 = null");
    ok(unibi_get_str(ut, unibi_lab_f9) == NULL, "lab_f9 = null");
    ok(unibi_get_str(ut, unibi_meta_off) == NULL, "meta_off = null");
    ok(unibi_get_str(ut, unibi_meta_on) == NULL, "meta_on = null");
    ok(strcmp(unibi_get_str(ut, unibi_newline), "\033E") == 0, "newline = \"%s\"", "\\033E");
    unibi_set_str(dt, unibi_newline, "\033E");
    ok(unibi_get_str(ut, unibi_pad_char) == NULL, "pad_char = null");
    ok(strcmp(unibi_get_str(ut, unibi_parm_dch), "\033[%p1%dP") == 0, "parm_dch = \"%s\"", "\\033[%p1%dP");
    unibi_set_str(dt, unibi_parm_dch, "\033[%p1%dP");
    ok(strcmp(unibi_get_str(ut, unibi_parm_delete_line), "\033[%p1%dM") == 0, "parm_delete_line = \"%s\"", "\\033[%p1%dM");
    unibi_set_str(dt, unibi_parm_delete_line, "\033[%p1%dM");
    ok(strcmp(unibi_get_str(ut, unibi_parm_down_cursor), "\033[%p1%dB") == 0, "parm_down_cursor = \"%s\"", "\\033[%p1%dB");
    unibi_set_str(dt, unibi_parm_down_cursor, "\033[%p1%dB");
    ok(strcmp(unibi_get_str(ut, unibi_parm_ich), "\033[%p1%d@") == 0, "parm_ich = \"%s\"", "\\033[%p1%d@");
    unibi_set_str(dt, unibi_parm_ich, "\033[%p1%d@");
    ok(strcmp(unibi_get_str(ut, unibi_parm_index), "\033[%p1%dS") == 0, "parm_index = \"%s\"", "\\033[%p1%dS");
    unibi_set_str(dt, unibi_parm_index, "\033[%p1%dS");
    ok(strcmp(unibi_get_str(ut, unibi_parm_insert_line), "\033[%p1%dL") == 0, "parm_insert_line = \"%s\"", "\\033[%p1%dL");
    unibi_set_str(dt, unibi_parm_insert_line, "\033[%p1%dL");
    ok(strcmp(unibi_get_str(ut, unibi_parm_left_cursor), "\033[%p1%dD") == 0, "parm_left_cursor = \"%s\"", "\\033[%p1%dD");
    unibi_set_str(dt, unibi_parm_left_cursor, "\033[%p1%dD");
    ok(strcmp(unibi_get_str(ut, unibi_parm_right_cursor), "\033[%p1%dC") == 0, "parm_right_cursor = \"%s\"", "\\033[%p1%dC");
    unibi_set_str(dt, unibi_parm_right_cursor, "\033[%p1%dC");
    ok(unibi_get_str(ut, unibi_parm_rindex) == NULL, "parm_rindex = null");
    ok(strcmp(unibi_get_str(ut, unibi_parm_up_cursor), "\033[%p1%dA") == 0, "parm_up_cursor = \"%s\"", "\\033[%p1%dA");
    unibi_set_str(dt, unibi_parm_up_cursor, "\033[%p1%dA");
    ok(unibi_get_str(ut, unibi_pkey_key) == NULL, "pkey_key = null");
    ok(unibi_get_str(ut, unibi_pkey_local) == NULL, "pkey_local = null");
    ok(unibi_get_str(ut, unibi_pkey_xmit) == NULL, "pkey_xmit = null");
    ok(unibi_get_str(ut, unibi_print_screen) == NULL, "print_screen = null");
    ok(unibi_get_str(ut, unibi_prtr_off) == NULL, "prtr_off = null");
    ok(unibi_get_str(ut, unibi_prtr_on) == NULL, "prtr_on = null");
    ok(unibi_get_str(ut, unibi_repeat_char) == NULL, "repeat_char = null");
    ok(unibi_get_str(ut, unibi_reset_1string) == NULL, "reset_1string = null");
    ok(strcmp(unibi_get_str(ut, unibi_reset_2string), "\033c\033[?1000l\033[?25h") == 0, "reset_2string = \"%s\"", "\\033c\\033[?1000l\\033[?25h");
    unibi_set_str(dt, unibi_reset_2string, "\033c\033[?1000l\033[?25h");
    ok(unibi_get_str(ut, unibi_reset_3string) == NULL, "reset_3string = null");
    ok(unibi_get_str(ut, unibi_reset_file) == NULL, "reset_file = null");
    ok(strcmp(unibi_get_str(ut, unibi_restore_cursor), "\0338") == 0, "restore_cursor = \"%s\"", "\\0338");
    unibi_set_str(dt, unibi_restore_cursor, "\0338");
    ok(strcmp(unibi_get_str(ut, unibi_row_address), "\033[%i%p1%dd") == 0, "row_address = \"%s\"", "\\033[%i%p1%dd");
    unibi_set_str(dt, unibi_row_address, "\033[%i%p1%dd");
    ok(strcmp(unibi_get_str(ut, unibi_save_cursor), "\0337") == 0, "save_cursor = \"%s\"", "\\0337");
    unibi_set_str(dt, unibi_save_cursor, "\0337");
    ok(strcmp(unibi_get_str(ut, unibi_scroll_forward), "\012") == 0, "scroll_forward = \"%s\"", "\\012");
    unibi_set_str(dt, unibi_scroll_forward, "\012");
    ok(strcmp(unibi_get_str(ut, unibi_scroll_reverse), "\033M") == 0, "scroll_reverse = \"%s\"", "\\033M");
    unibi_set_str(dt, unibi_scroll_reverse, "\033M");
    ok(strcmp(unibi_get_str(ut, unibi_set_attributes), "\033[0%?%p6%t;1%;%?%p1%t;3%;%?%p2%t;4%;%?%p3%t;7%;%?%p4%t;5%;%?%p5%t;2%;m%?%p9%t\016%e\017%;") == 0, "set_attributes = \"%s\"", "\\033[0%?%p6%t;1%;%?%p1%t;3%;%?%p2%t;4%;%?%p3%t;7%;%?%p4%t;5%;%?%p5%t;2%;m%?%p9%t\\016%e\\017%;");
    unibi_set_str(dt, unibi_set_attributes, "\033[0%?%p6%t;1%;%?%p1%t;3%;%?%p2%t;4%;%?%p3%t;7%;%?%p4%t;5%;%?%p5%t;2%;m%?%p9%t\016%e\017%;");
    ok(strcmp(unibi_get_str(ut, unibi_set_tab), "\033H") == 0, "set_tab = \"%s\"", "\\033H");
    unibi_set_str(dt, unibi_set_tab, "\033H");
    ok(unibi_get_str(ut, unibi_set_window) == NULL, "set_window = null");
    ok(strcmp(unibi_get_str(ut, unibi_tab), "\011") == 0, "tab = \"%s\"", "\\011");
    unibi_set_str(dt, unibi_tab, "\011");
    ok(unibi_get_str(ut, unibi_to_status_line) == NULL, "to_status_line = null");
    ok(unibi_get_str(ut, unibi_underline_char) == NULL, "underline_char = null");
    ok(unibi_get_str(ut, unibi_up_half_line) == NULL, "up_half_line = null");
    ok(unibi_get_str(ut, unibi_init_prog) == NULL, "init_prog = null");
    ok(unibi_get_str(ut, unibi_key_a1) == NULL, "key_a1 = null");
    ok(unibi_get_str(ut, unibi_key_a3) == NULL, "key_a3 = null");
    ok(unibi_get_str(ut, unibi_key_b2) == NULL, "key_b2 = null");
    ok(unibi_get_str(ut, unibi_key_c1) == NULL, "key_c1 = null");
    ok(unibi_get_str(ut, unibi_key_c3) == NULL, "key_c3 = null");
    ok(unibi_get_str(ut, unibi_prtr_non) == NULL, "prtr_non = null");
    ok(unibi_get_str(ut, unibi_char_padding) == NULL, "char_padding = null");
    ok(strcmp(unibi_get_str(ut, unibi_acs_chars), "++,,--..00``aaffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~") == 0, "acs_chars = \"%s\"", "++,,--..00``aaffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~");
    unibi_set_str(dt, unibi_acs_chars, "++,,--..00``aaffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~");
    ok(unibi_get_str(ut, unibi_plab_norm) == NULL, "plab_norm = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_btab), "\033[Z") == 0, "key_btab = \"%s\"", "\\033[Z");
    unibi_set_str(dt, unibi_key_btab, "\033[Z");
    ok(unibi_get_str(ut, unibi_enter_xon_mode) == NULL, "enter_xon_mode = null");
    ok(unibi_get_str(ut, unibi_exit_xon_mode) == NULL, "exit_xon_mode = null");
    ok(unibi_get_str(ut, unibi_enter_am_mode) == NULL, "enter_am_mode = null");
    ok(unibi_get_str(ut, unibi_exit_am_mode) == NULL, "exit_am_mode = null");
    ok(unibi_get_str(ut, unibi_xon_character) == NULL, "xon_character = null");
    ok(unibi_get_str(ut, unibi_xoff_character) == NULL, "xoff_character = null");
    ok(strcmp(unibi_get_str(ut, unibi_ena_acs), "\033(B\033)0") == 0, "ena_acs = \"%s\"", "\\033(B\\033)0");
    unibi_set_str(dt, unibi_ena_acs, "\033(B\033)0");
    ok(unibi_get_str(ut, unibi_label_on) == NULL, "label_on = null");
    ok(unibi_get_str(ut, unibi_label_off) == NULL, "label_off = null");
    ok(unibi_get_str(ut, unibi_key_beg) == NULL, "key_beg = null");
    ok(unibi_get_str(ut, unibi_key_cancel) == NULL, "key_cancel = null");
    ok(unibi_get_str(ut, unibi_key_close) == NULL, "key_close = null");
    ok(unibi_get_str(ut, unibi_key_command) == NULL, "key_command = null");
    ok(unibi_get_str(ut, unibi_key_copy) == NULL, "key_copy = null");
    ok(unibi_get_str(ut, unibi_key_create) == NULL, "key_create = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_end), "\033[4~") == 0, "key_end = \"%s\"", "\\033[4~");
    unibi_set_str(dt, unibi_key_end, "\033[4~");
    ok(unibi_get_str(ut, unibi_key_enter) == NULL, "key_enter = null");
    ok(unibi_get_str(ut, unibi_key_exit) == NULL, "key_exit = null");
    ok(unibi_get_str(ut, unibi_key_find) == NULL, "key_find = null");
    ok(unibi_get_str(ut, unibi_key_help) == NULL, "key_help = null");
    ok(unibi_get_str(ut, unibi_key_mark) == NULL, "key_mark = null");
    ok(unibi_get_str(ut, unibi_key_message) == NULL, "key_message = null");
    ok(unibi_get_str(ut, unibi_key_move) == NULL, "key_move = null");
    ok(unibi_get_str(ut, unibi_key_next) == NULL, "key_next = null");
    ok(unibi_get_str(ut, unibi_key_open) == NULL, "key_open = null");
    ok(unibi_get_str(ut, unibi_key_options) == NULL, "key_options = null");
    ok(unibi_get_str(ut, unibi_key_previous) == NULL, "key_previous = null");
    ok(unibi_get_str(ut, unibi_key_print) == NULL, "key_print = null");
    ok(unibi_get_str(ut, unibi_key_redo) == NULL, "key_redo = null");
    ok(unibi_get_str(ut, unibi_key_reference) == NULL, "key_reference = null");
    ok(unibi_get_str(ut, unibi_key_refresh) == NULL, "key_refresh = null");
    ok(unibi_get_str(ut, unibi_key_replace) == NULL, "key_replace = null");
    ok(unibi_get_str(ut, unibi_key_restart) == NULL, "key_restart = null");
    ok(unibi_get_str(ut, unibi_key_resume) == NULL, "key_resume = null");
    ok(unibi_get_str(ut, unibi_key_save) == NULL, "key_save = null");
    ok(unibi_get_str(ut, unibi_key_suspend) == NULL, "key_suspend = null");
    ok(unibi_get_str(ut, unibi_key_undo) == NULL, "key_undo = null");
    ok(unibi_get_str(ut, unibi_key_sbeg) == NULL, "key_sbeg = null");
    ok(unibi_get_str(ut, unibi_key_scancel) == NULL, "key_scancel = null");
    ok(unibi_get_str(ut, unibi_key_scommand) == NULL, "key_scommand = null");
    ok(unibi_get_str(ut, unibi_key_scopy) == NULL, "key_scopy = null");
    ok(unibi_get_str(ut, unibi_key_screate) == NULL, "key_screate = null");
    ok(unibi_get_str(ut, unibi_key_sdc) == NULL, "key_sdc = null");
    ok(unibi_get_str(ut, unibi_key_sdl) == NULL, "key_sdl = null");
    ok(unibi_get_str(ut, unibi_key_select) == NULL, "key_select = null");
    ok(unibi_get_str(ut, unibi_key_send) == NULL, "key_send = null");
    ok(unibi_get_str(ut, unibi_key_seol) == NULL, "key_seol = null");
    ok(unibi_get_str(ut, unibi_key_sexit) == NULL, "key_sexit = null");
    ok(unibi_get_str(ut, unibi_key_sfind) == NULL, "key_sfind = null");
    ok(unibi_get_str(ut, unibi_key_shelp) == NULL, "key_shelp = null");
    ok(unibi_get_str(ut, unibi_key_shome) == NULL, "key_shome = null");
    ok(unibi_get_str(ut, unibi_key_sic) == NULL, "key_sic = null");
    ok(unibi_get_str(ut, unibi_key_sleft) == NULL, "key_sleft = null");
    ok(unibi_get_str(ut, unibi_key_smessage) == NULL, "key_smessage = null");
    ok(unibi_get_str(ut, unibi_key_smove) == NULL, "key_smove = null");
    ok(unibi_get_str(ut, unibi_key_snext) == NULL, "key_snext = null");
    ok(unibi_get_str(ut, unibi_key_soptions) == NULL, "key_soptions = null");
    ok(unibi_get_str(ut, unibi_key_sprevious) == NULL, "key_sprevious = null");
    ok(unibi_get_str(ut, unibi_key_sprint) == NULL, "key_sprint = null");
    ok(unibi_get_str(ut, unibi_key_sredo) == NULL, "key_sredo = null");
    ok(unibi_get_str(ut, unibi_key_sreplace) == NULL, "key_sreplace = null");
    ok(unibi_get_str(ut, unibi_key_sright) == NULL, "key_sright = null");
    ok(unibi_get_str(ut, unibi_key_srsume) == NULL, "key_srsume = null");
    ok(unibi_get_str(ut, unibi_key_ssave) == NULL, "key_ssave = null");
    ok(unibi_get_str(ut, unibi_key_ssuspend) == NULL, "key_ssuspend = null");
    ok(unibi_get_str(ut, unibi_key_sundo) == NULL, "key_sundo = null");
    ok(unibi_get_str(ut, unibi_req_for_input) == NULL, "req_for_input = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_f11), "\033[23~") == 0, "key_f11 = \"%s\"", "\\033[23~");
    unibi_set_str(dt, unibi_key_f11, "\033[23~");
    ok(strcmp(unibi_get_str(ut, unibi_key_f12), "\033[24~") == 0, "key_f12 = \"%s\"", "\\033[24~");
    unibi_set_str(dt, unibi_key_f12, "\033[24~");
    ok(unibi_get_str(ut, unibi_key_f13) == NULL, "key_f13 = null");
    ok(unibi_get_str(ut, unibi_key_f14) == NULL, "key_f14 = null");
    ok(unibi_get_str(ut, unibi_key_f15) == NULL, "key_f15 = null");
    ok(unibi_get_str(ut, unibi_key_f16) == NULL, "key_f16 = null");
    ok(unibi_get_str(ut, unibi_key_f17) == NULL, "key_f17 = null");
    ok(unibi_get_str(ut, unibi_key_f18) == NULL, "key_f18 = null");
    ok(unibi_get_str(ut, unibi_key_f19) == NULL, "key_f19 = null");
    ok(unibi_get_str(ut, unibi_key_f20) == NULL, "key_f20 = null");
    ok(unibi_get_str(ut, unibi_key_f21) == NULL, "key_f21 = null");
    ok(unibi_get_str(ut, unibi_key_f22) == NULL, "key_f22 = null");
    ok(unibi_get_str(ut, unibi_key_f23) == NULL, "key_f23 = null");
    ok(unibi_get_str(ut, unibi_key_f24) == NULL, "key_f24 = null");
    ok(unibi_get_str(ut, unibi_key_f25) == NULL, "key_f25 = null");
    ok(unibi_get_str(ut, unibi_key_f26) == NULL, "key_f26 = null");
    ok(unibi_get_str(ut, unibi_key_f27) == NULL, "key_f27 = null");
    ok(unibi_get_str(ut, unibi_key_f28) == NULL, "key_f28 = null");
    ok(unibi_get_str(ut, unibi_key_f29) == NULL, "key_f29 = null");
    ok(unibi_get_str(ut, unibi_key_f30) == NULL, "key_f30 = null");
    ok(unibi_get_str(ut, unibi_key_f31) == NULL, "key_f31 = null");
    ok(unibi_get_str(ut, unibi_key_f32) == NULL, "key_f32 = null");
    ok(unibi_get_str(ut, unibi_key_f33) == NULL, "key_f33 = null");
    ok(unibi_get_str(ut, unibi_key_f34) == NULL, "key_f34 = null");
    ok(unibi_get_str(ut, unibi_key_f35) == NULL, "key_f35 = null");
    ok(unibi_get_str(ut, unibi_key_f36) == NULL, "key_f36 = null");
    ok(unibi_get_str(ut, unibi_key_f37) == NULL, "key_f37 = null");
    ok(unibi_get_str(ut, unibi_key_f38) == NULL, "key_f38 = null");
    ok(unibi_get_str(ut, unibi_key_f39) == NULL, "key_f39 = null");
    ok(unibi_get_str(ut, unibi_key_f40) == NULL, "key_f40 = null");
    ok(unibi_get_str(ut, unibi_key_f41) == NULL, "key_f41 = null");
    ok(unibi_get_str(ut, unibi_key_f42) == NULL, "key_f42 = null");
    ok(unibi_get_str(ut, unibi_key_f43) == NULL, "key_f43 = null");
    ok(unibi_get_str(ut, unibi_key_f44) == NULL, "key_f44 = null");
    ok(unibi_get_str(ut, unibi_key_f45) == NULL, "key_f45 = null");
    ok(unibi_get_str(ut, unibi_key_f46) == NULL, "key_f46 = null");
    ok(unibi_get_str(ut, unibi_key_f47) == NULL, "key_f47 = null");
    ok(unibi_get_str(ut, unibi_key_f48) == NULL, "key_f48 = null");
    ok(unibi_get_str(ut, unibi_key_f49) == NULL, "key_f49 = null");
    ok(unibi_get_str(ut, unibi_key_f50) == NULL, "key_f50 = null");
    ok(unibi_get_str(ut, unibi_key_f51) == NULL, "key_f51 = null");
    ok(unibi_get_str(ut, unibi_key_f52) == NULL, "key_f52 = null");
    ok(unibi_get_str(ut, unibi_key_f53) == NULL, "key_f53 = null");
    ok(unibi_get_str(ut, unibi_key_f54) == NULL, "key_f54 = null");
    ok(unibi_get_str(ut, unibi_key_f55) == NULL, "key_f55 = null");
    ok(unibi_get_str(ut, unibi_key_f56) == NULL, "key_f56 = null");
    ok(unibi_get_str(ut, unibi_key_f57) == NULL, "key_f57 = null");
    ok(unibi_get_str(ut, unibi_key_f58) == NULL, "key_f58 = null");
    ok(unibi_get_str(ut, unibi_key_f59) == NULL, "key_f59 = null");
    ok(unibi_get_str(ut, unibi_key_f60) == NULL, "key_f60 = null");
    ok(unibi_get_str(ut, unibi_key_f61) == NULL, "key_f61 = null");
    ok(unibi_get_str(ut, unibi_key_f62) == NULL, "key_f62 = null");
    ok(unibi_get_str(ut, unibi_key_f63) == NULL, "key_f63 = null");
    ok(strcmp(unibi_get_str(ut, unibi_clr_bol), "\033[1K") == 0, "clr_bol = \"%s\"", "\\033[1K");
    unibi_set_str(dt, unibi_clr_bol, "\033[1K");
    ok(unibi_get_str(ut, unibi_clear_margins) == NULL, "clear_margins = null");
    ok(unibi_get_str(ut, unibi_set_left_margin) == NULL, "set_left_margin = null");
    ok(unibi_get_str(ut, unibi_set_right_margin) == NULL, "set_right_margin = null");
    ok(unibi_get_str(ut, unibi_label_format) == NULL, "label_format = null");
    ok(unibi_get_str(ut, unibi_set_clock) == NULL, "set_clock = null");
    ok(unibi_get_str(ut, unibi_display_clock) == NULL, "display_clock = null");
    ok(unibi_get_str(ut, unibi_remove_clock) == NULL, "remove_clock = null");
    ok(unibi_get_str(ut, unibi_create_window) == NULL, "create_window = null");
    ok(unibi_get_str(ut, unibi_goto_window) == NULL, "goto_window = null");
    ok(unibi_get_str(ut, unibi_hangup) == NULL, "hangup = null");
    ok(unibi_get_str(ut, unibi_dial_phone) == NULL, "dial_phone = null");
    ok(unibi_get_str(ut, unibi_quick_dial) == NULL, "quick_dial = null");
    ok(unibi_get_str(ut, unibi_tone) == NULL, "tone = null");
    ok(unibi_get_str(ut, unibi_pulse) == NULL, "pulse = null");
    ok(unibi_get_str(ut, unibi_flash_hook) == NULL, "flash_hook = null");
    ok(unibi_get_str(ut, unibi_fixed_pause) == NULL, "fixed_pause = null");
    ok(unibi_get_str(ut, unibi_wait_tone) == NULL, "wait_tone = null");
    ok(unibi_get_str(ut, unibi_user0) == NULL, "user0 = null");
    ok(unibi_get_str(ut, unibi_user1) == NULL, "user1 = null");
    ok(unibi_get_str(ut, unibi_user2) == NULL, "user2 = null");
    ok(unibi_get_str(ut, unibi_user3) == NULL, "user3 = null");
    ok(unibi_get_str(ut, unibi_user4) == NULL, "user4 = null");
    ok(unibi_get_str(ut, unibi_user5) == NULL, "user5 = null");
    ok(unibi_get_str(ut, unibi_user6) == NULL, "user6 = null");
    ok(unibi_get_str(ut, unibi_user7) == NULL, "user7 = null");
    ok(unibi_get_str(ut, unibi_user8) == NULL, "user8 = null");
    ok(unibi_get_str(ut, unibi_user9) == NULL, "user9 = null");
    ok(strcmp(unibi_get_str(ut, unibi_orig_pair), "\033[39;49m") == 0, "orig_pair = \"%s\"", "\\033[39;49m");
    unibi_set_str(dt, unibi_orig_pair, "\033[39;49m");
    ok(unibi_get_str(ut, unibi_orig_colors) == NULL, "orig_colors = null");
    ok(unibi_get_str(ut, unibi_initialize_color) == NULL, "initialize_color = null");
    ok(unibi_get_str(ut, unibi_initialize_pair) == NULL, "initialize_pair = null");
    ok(unibi_get_str(ut, unibi_set_color_pair) == NULL, "set_color_pair = null");
    ok(unibi_get_str(ut, unibi_set_foreground) == NULL, "set_foreground = null");
    ok(unibi_get_str(ut, unibi_set_background) == NULL, "set_background = null");
    ok(unibi_get_str(ut, unibi_change_char_pitch) == NULL, "change_char_pitch = null");
    ok(unibi_get_str(ut, unibi_change_line_pitch) == NULL, "change_line_pitch = null");
    ok(unibi_get_str(ut, unibi_change_res_horz) == NULL, "change_res_horz = null");
    ok(unibi_get_str(ut, unibi_change_res_vert) == NULL, "change_res_vert = null");
    ok(unibi_get_str(ut, unibi_define_char) == NULL, "define_char = null");
    ok(unibi_get_str(ut, unibi_enter_doublewide_mode) == NULL, "enter_doublewide_mode = null");
    ok(unibi_get_str(ut, unibi_enter_draft_quality) == NULL, "enter_draft_quality = null");
    ok(unibi_get_str(ut, unibi_enter_italics_mode) == NULL, "enter_italics_mode = null");
    ok(unibi_get_str(ut, unibi_enter_leftward_mode) == NULL, "enter_leftward_mode = null");
    ok(unibi_get_str(ut, unibi_enter_micro_mode) == NULL, "enter_micro_mode = null");
    ok(unibi_get_str(ut, unibi_enter_near_letter_quality) == NULL, "enter_near_letter_quality = null");
    ok(unibi_get_str(ut, unibi_enter_normal_quality) == NULL, "enter_normal_quality = null");
    ok(unibi_get_str(ut, unibi_enter_shadow_mode) == NULL, "enter_shadow_mode = null");
    ok(unibi_get_str(ut, unibi_enter_subscript_mode) == NULL, "enter_subscript_mode = null");
    ok(unibi_get_str(ut, unibi_enter_superscript_mode) == NULL, "enter_superscript_mode = null");
    ok(unibi_get_str(ut, unibi_enter_upward_mode) == NULL, "enter_upward_mode = null");
    ok(unibi_get_str(ut, unibi_exit_doublewide_mode) == NULL, "exit_doublewide_mode = null");
    ok(unibi_get_str(ut, unibi_exit_italics_mode) == NULL, "exit_italics_mode = null");
    ok(unibi_get_str(ut, unibi_exit_leftward_mode) == NULL, "exit_leftward_mode = null");
    ok(unibi_get_str(ut, unibi_exit_micro_mode) == NULL, "exit_micro_mode = null");
    ok(unibi_get_str(ut, unibi_exit_shadow_mode) == NULL, "exit_shadow_mode = null");
    ok(unibi_get_str(ut, unibi_exit_subscript_mode) == NULL, "exit_subscript_mode = null");
    ok(unibi_get_str(ut, unibi_exit_superscript_mode) == NULL, "exit_superscript_mode = null");
    ok(unibi_get_str(ut, unibi_exit_upward_mode) == NULL, "exit_upward_mode = null");
    ok(unibi_get_str(ut, unibi_micro_column_address) == NULL, "micro_column_address = null");
    ok(unibi_get_str(ut, unibi_micro_down) == NULL, "micro_down = null");
    ok(unibi_get_str(ut, unibi_micro_left) == NULL, "micro_left = null");
    ok(unibi_get_str(ut, unibi_micro_right) == NULL, "micro_right = null");
    ok(unibi_get_str(ut, unibi_micro_row_address) == NULL, "micro_row_address = null");
    ok(unibi_get_str(ut, unibi_micro_up) == NULL, "micro_up = null");
    ok(unibi_get_str(ut, unibi_order_of_pins) == NULL, "order_of_pins = null");
    ok(unibi_get_str(ut, unibi_parm_down_micro) == NULL, "parm_down_micro = null");
    ok(unibi_get_str(ut, unibi_parm_left_micro) == NULL, "parm_left_micro = null");
    ok(unibi_get_str(ut, unibi_parm_right_micro) == NULL, "parm_right_micro = null");
    ok(unibi_get_str(ut, unibi_parm_up_micro) == NULL, "parm_up_micro = null");
    ok(unibi_get_str(ut, unibi_select_char_set) == NULL, "select_char_set = null");
    ok(unibi_get_str(ut, unibi_set_bottom_margin) == NULL, "set_bottom_margin = null");
    ok(unibi_get_str(ut, unibi_set_bottom_margin_parm) == NULL, "set_bottom_margin_parm = null");
    ok(unibi_get_str(ut, unibi_set_left_margin_parm) == NULL, "set_left_margin_parm = null");
    ok(unibi_get_str(ut, unibi_set_right_margin_parm) == NULL, "set_right_margin_parm = null");
    ok(unibi_get_str(ut, unibi_set_top_margin) == NULL, "set_top_margin = null");
    ok(unibi_get_str(ut, unibi_set_top_margin_parm) == NULL, "set_top_margin_parm = null");
    ok(unibi_get_str(ut, unibi_start_bit_image) == NULL, "start_bit_image = null");
    ok(unibi_get_str(ut, unibi_start_char_set_def) == NULL, "start_char_set_def = null");
    ok(unibi_get_str(ut, unibi_stop_bit_image) == NULL, "stop_bit_image = null");
    ok(unibi_get_str(ut, unibi_stop_char_set_def) == NULL, "stop_char_set_def = null");
    ok(unibi_get_str(ut, unibi_subscript_characters) == NULL, "subscript_characters = null");
    ok(unibi_get_str(ut, unibi_superscript_characters) == NULL, "superscript_characters = null");
    ok(unibi_get_str(ut, unibi_these_cause_cr) == NULL, "these_cause_cr = null");
    ok(unibi_get_str(ut, unibi_zero_motion) == NULL, "zero_motion = null");
    ok(unibi_get_str(ut, unibi_char_set_names) == NULL, "char_set_names = null");
    ok(strcmp(unibi_get_str(ut, unibi_key_mouse), "\033[M") == 0, "key_mouse = \"%s\"", "\\033[M");
    unibi_set_str(dt, unibi_key_mouse, "\033[M");
    ok(unibi_get_str(ut, unibi_mouse_info) == NULL, "mouse_info = null");
    ok(unibi_get_str(ut, unibi_req_mouse_pos) == NULL, "req_mouse_pos = null");
    ok(unibi_get_str(ut, unibi_get_mouse) == NULL, "get_mouse = null");
    ok(strcmp(unibi_get_str(ut, unibi_set_a_foreground), "\033[3%p1%dm") == 0, "set_a_foreground = \"%s\"", "\\033[3%p1%dm");
    unibi_set_str(dt, unibi_set_a_foreground, "\033[3%p1%dm");
    ok(strcmp(unibi_get_str(ut, unibi_set_a_background), "\033[4%p1%dm") == 0, "set_a_background = \"%s\"", "\\033[4%p1%dm");
    unibi_set_str(dt, unibi_set_a_background, "\033[4%p1%dm");
    ok(unibi_get_str(ut, unibi_pkey_plab) == NULL, "pkey_plab = null");
    ok(unibi_get_str(ut, unibi_device_type) == NULL, "device_type = null");
    ok(unibi_get_str(ut, unibi_code_set_init) == NULL, "code_set_init = null");
    ok(unibi_get_str(ut, unibi_set0_des_seq) == NULL, "set0_des_seq = null");
    ok(unibi_get_str(ut, unibi_set1_des_seq) == NULL, "set1_des_seq = null");
    ok(unibi_get_str(ut, unibi_set2_des_seq) == NULL, "set2_des_seq = null");
    ok(unibi_get_str(ut, unibi_set3_des_seq) == NULL, "set3_des_seq = null");
    ok(unibi_get_str(ut, unibi_set_lr_margin) == NULL, "set_lr_margin = null");
    ok(unibi_get_str(ut, unibi_set_tb_margin) == NULL, "set_tb_margin = null");
    ok(unibi_get_str(ut, unibi_bit_image_repeat) == NULL, "bit_image_repeat = null");
    ok(unibi_get_str(ut, unibi_bit_image_newline) == NULL, "bit_image_newline = null");
    ok(unibi_get_str(ut, unibi_bit_image_carriage_return) == NULL, "bit_image_carriage_return = null");
    ok(unibi_get_str(ut, unibi_color_names) == NULL, "color_names = null");
    ok(unibi_get_str(ut, unibi_define_bit_image_region) == NULL, "define_bit_image_region = null");
    ok(unibi_get_str(ut, unibi_end_bit_image_region) == NULL, "end_bit_image_region = null");
    ok(unibi_get_str(ut, unibi_set_color_band) == NULL, "set_color_band = null");
    ok(unibi_get_str(ut, unibi_set_page_length) == NULL, "set_page_length = null");
    ok(unibi_get_str(ut, unibi_display_pc_char) == NULL, "display_pc_char = null");
    ok(unibi_get_str(ut, unibi_enter_pc_charset_mode) == NULL, "enter_pc_charset_mode = null");
    ok(unibi_get_str(ut, unibi_exit_pc_charset_mode) == NULL, "exit_pc_charset_mode = null");
    ok(unibi_get_str(ut, unibi_enter_scancode_mode) == NULL, "enter_scancode_mode = null");
    ok(unibi_get_str(ut, unibi_exit_scancode_mode) == NULL, "exit_scancode_mode = null");
    ok(unibi_get_str(ut, unibi_pc_term_options) == NULL, "pc_term_options = null");
    ok(unibi_get_str(ut, unibi_scancode_escape) == NULL, "scancode_escape = null");
    ok(unibi_get_str(ut, unibi_alt_scancode_esc) == NULL, "alt_scancode_esc = null");
    ok(unibi_get_str(ut, unibi_enter_horizontal_hl_mode) == NULL, "enter_horizontal_hl_mode = null");
    ok(unibi_get_str(ut, unibi_enter_left_hl_mode) == NULL, "enter_left_hl_mode = null");
    ok(unibi_get_str(ut, unibi_enter_low_hl_mode) == NULL, "enter_low_hl_mode = null");
    ok(unibi_get_str(ut, unibi_enter_right_hl_mode) == NULL, "enter_right_hl_mode = null");
    ok(unibi_get_str(ut, unibi_enter_top_hl_mode) == NULL, "enter_top_hl_mode = null");
    ok(unibi_get_str(ut, unibi_enter_vertical_hl_mode) == NULL, "enter_vertical_hl_mode = null");
    ok(unibi_get_str(ut, unibi_set_a_attributes) == NULL, "set_a_attributes = null");
    ok(unibi_get_str(ut, unibi_set_pglen_inch) == NULL, "set_pglen_inch = null");
    ok(unibi_get_str(ut, unibi_termcap_init2) == NULL, "termcap_init2 = null");
    ok(unibi_get_str(ut, unibi_termcap_reset) == NULL, "termcap_reset = null");
    ok(unibi_get_str(ut, unibi_linefeed_if_not_lf) == NULL, "linefeed_if_not_lf = null");
    ok(unibi_get_str(ut, unibi_backspace_if_not_bs) == NULL, "backspace_if_not_bs = null");
    ok(unibi_get_str(ut, unibi_other_non_function_keys) == NULL, "other_non_function_keys = null");
    ok(unibi_get_str(ut, unibi_arrow_key_map) == NULL, "arrow_key_map = null");
    ok(unibi_get_str(ut, unibi_acs_ulcorner) == NULL, "acs_ulcorner = null");
    ok(unibi_get_str(ut, unibi_acs_llcorner) == NULL, "acs_llcorner = null");
    ok(unibi_get_str(ut, unibi_acs_urcorner) == NULL, "acs_urcorner = null");
    ok(unibi_get_str(ut, unibi_acs_lrcorner) == NULL, "acs_lrcorner = null");
    ok(unibi_get_str(ut, unibi_acs_ltee) == NULL, "acs_ltee = null");
    ok(unibi_get_str(ut, unibi_acs_rtee) == NULL, "acs_rtee = null");
    ok(unibi_get_str(ut, unibi_acs_btee) == NULL, "acs_btee = null");
    ok(unibi_get_str(ut, unibi_acs_ttee) == NULL, "acs_ttee = null");
    ok(unibi_get_str(ut, unibi_acs_hline) == NULL, "acs_hline = null");
    ok(unibi_get_str(ut, unibi_acs_vline) == NULL, "acs_vline = null");
    ok(unibi_get_str(ut, unibi_acs_plus) == NULL, "acs_plus = null");
    ok(unibi_get_str(ut, unibi_memory_lock) == NULL, "memory_lock = null");
    ok(unibi_get_str(ut, unibi_memory_unlock) == NULL, "memory_unlock = null");
    ok(unibi_get_str(ut, unibi_box_chars_1) == NULL, "box_chars_1 = null");

    note("extended boolean capabilities");
    {
        const size_t n_ext = unibi_count_ext_bool(ut);
        ok(n_ext == 3, "#ext_bool = 3");
        ok(0 < n_ext && unibi_get_ext_bool(ut, 0) == 1, "ext_bool[0].value = 1");
        ok(0 < n_ext && strcmp(unibi_get_ext_bool_name(ut, 0), "AX") == 0, "ext_bool[0].name = \"%s\"", "AX");
        unibi_add_ext_bool(dt, "AX", 1);
        ok(1 < n_ext && unibi_get_ext_bool(ut, 1) == 1, "ext_bool[1].value = 1");
        ok(1 < n_ext && strcmp(unibi_get_ext_bool_name(ut, 1), "G0") == 0, "ext_bool[1].name = \"%s\"", "G0");
        unibi_add_ext_bool(dt, "G0", 1);
        ok(2 < n_ext && unibi_get_ext_bool(ut, 2) == 0, "ext_bool[2].value = 0");
        ok(2 < n_ext && strcmp(unibi_get_ext_bool_name(ut, 2), "XT") == 0, "ext_bool[2].name = \"%s\"", "XT");
        unibi_add_ext_bool(dt, "XT", 0);
    }

    note("extended numeric capabilities");
    {
        const size_t n_ext = unibi_count_ext_num(ut);
        ok(n_ext == 1, "#ext_num = 1");
        ok(0 < n_ext && unibi_get_ext_num(ut, 0) == 1, "ext_num[0].value = 1");
        ok(0 < n_ext && strcmp(unibi_get_ext_num_name(ut, 0), "U8") == 0, "ext_num[0].name = \"%s\"", "U8");
        unibi_add_ext_num(dt, "U8", 1);
    }

    note("extended string capabilities");
    {
        const size_t n_ext = unibi_count_ext_str(ut);
        ok(n_ext == 12, "#ext_str = 12");
        ok(0 < n_ext && strcmp(unibi_get_ext_str(ut, 0), "\033(B") == 0, "ext_str[0].value = \"%s\"", "\\033(B");
        unibi_add_ext_str(dt, "E0", "\033(B");
        ok(0 < n_ext && strcmp(unibi_get_ext_str_name(ut, 0), "E0") == 0, "ext_str[0].name = \"%s\"", "E0");
        ok(1 < n_ext && unibi_get_ext_str(ut, 1) == NULL, "ext_str[1].value = null");
        unibi_add_ext_str(dt, "E3", NULL);
        ok(1 < n_ext && strcmp(unibi_get_ext_str_name(ut, 1), "E3") == 0, "ext_str[1].name = \"%s\"", "E3");
        ok(2 < n_ext && strcmp(unibi_get_ext_str(ut, 2), "\033(%p1%c") == 0, "ext_str[2].value = \"%s\"", "\\033(%p1%c");
        unibi_add_ext_str(dt, "S0", "\033(%p1%c");
        ok(2 < n_ext && strcmp(unibi_get_ext_str_name(ut, 2), "S0") == 0, "ext_str[2].name = \"%s\"", "S0");
        ok(3 < n_ext && unibi_get_ext_str(ut, 3) == NULL, "ext_str[3].value = null");
        unibi_add_ext_str(dt, "TS", NULL);
        ok(3 < n_ext && strcmp(unibi_get_ext_str_name(ut, 3), "TS") == 0, "ext_str[3].name = \"%s\"", "TS");
        ok(4 < n_ext && unibi_get_ext_str(ut, 4) == NULL, "ext_str[4].value = null");
        unibi_add_ext_str(dt, "XM", NULL);
        ok(4 < n_ext && strcmp(unibi_get_ext_str_name(ut, 4), "XM") == 0, "ext_str[4].name = \"%s\"", "XM");
        ok(5 < n_ext && unibi_get_ext_str(ut, 5) == NULL, "ext_str[5].value = null");
        unibi_add_ext_str(dt, "kEND5", NULL);
        ok(5 < n_ext && strcmp(unibi_get_ext_str_name(ut, 5), "kEND5") == 0, "ext_str[5].name = \"%s\"", "kEND5");
        ok(6 < n_ext && unibi_get_ext_str(ut, 6) == NULL, "ext_str[6].value = null");
        unibi_add_ext_str(dt, "kHOM5", NULL);
        ok(6 < n_ext && strcmp(unibi_get_ext_str_name(ut, 6), "kHOM5") == 0, "ext_str[6].name = \"%s\"", "kHOM5");
        ok(7 < n_ext && unibi_get_ext_str(ut, 7) == NULL, "ext_str[7].value = null");
        unibi_add_ext_str(dt, "ka2", NULL);
        ok(7 < n_ext && strcmp(unibi_get_ext_str_name(ut, 7), "ka2") == 0, "ext_str[7].name = \"%s\"", "ka2");
        ok(8 < n_ext && unibi_get_ext_str(ut, 8) == NULL, "ext_str[8].value = null");
        unibi_add_ext_str(dt, "kb1", NULL);
        ok(8 < n_ext && strcmp(unibi_get_ext_str_name(ut, 8), "kb1") == 0, "ext_str[8].name = \"%s\"", "kb1");
        ok(9 < n_ext && unibi_get_ext_str(ut, 9) == NULL, "ext_str[9].value = null");
        unibi_add_ext_str(dt, "kb3", NULL);
        ok(9 < n_ext && strcmp(unibi_get_ext_str_name(ut, 9), "kb3") == 0, "ext_str[9].name = \"%s\"", "kb3");
        ok(10 < n_ext && unibi_get_ext_str(ut, 10) == NULL, "ext_str[10].value = null");
        unibi_add_ext_str(dt, "kc2", NULL);
        ok(10 < n_ext && strcmp(unibi_get_ext_str_name(ut, 10), "kc2") == 0, "ext_str[10].name = \"%s\"", "kc2");
        ok(11 < n_ext && unibi_get_ext_str(ut, 11) == NULL, "ext_str[11].value = null");
        unibi_add_ext_str(dt, "xm", NULL);
        ok(11 < n_ext && strcmp(unibi_get_ext_str_name(ut, 11), "xm") == 0, "ext_str[11].name = \"%s\"", "xm");
    }

    {
        char buf[sizeof terminfo];
        size_t r = unibi_dump(ut, buf, sizeof buf);
        ok(r == sizeof terminfo, "redump size == orig size");
        ok(memcmp(terminfo, buf, sizeof buf) == 0, "redump == orig");
    }

    {
        char buf[sizeof terminfo];
        size_t r = unibi_dump(dt, buf, sizeof buf);
        ok(r == sizeof terminfo, "dummy redump size == orig size");
        ok(memcmp(terminfo, buf, sizeof buf) == 0, "dummy redump == orig");
    }

    unibi_destroy(ut);
    ok(1, "object destroyed");

    unibi_destroy(dt);
    ok(1, "dummy object destroyed");

    return 0;
}

static void setup(void) {
    plan(543);
}
