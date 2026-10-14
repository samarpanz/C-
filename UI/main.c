#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"

static int ui_text_width(mu_Font font, const char *text, int len) {
    (void)font;
    return r_get_text_width(text, len);
}

static int ui_text_height(mu_Font font) {
    (void)font;
    return r_get_text_height();
}

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL video initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    r_init();

    mu_Context ctx;
    mu_init(&ctx);
    ctx.text_width = ui_text_width;
    ctx.text_height = ui_text_height;

    int running = 1;
    int clicks = 0;
    int enabled = 1;
    mu_Real slider = 0.5f;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_MOUSEMOTION:
                    mu_input_mousemove(&ctx, e.motion.x, e.motion.y);
                    break;
                case SDL_MOUSEBUTTONDOWN: {
                    int btn = 0;
                    switch (e.button.button) {
                        case SDL_BUTTON_LEFT: btn = MU_MOUSE_LEFT; break;
                        case SDL_BUTTON_MIDDLE: btn = MU_MOUSE_MIDDLE; break;
                        case SDL_BUTTON_RIGHT: btn = MU_MOUSE_RIGHT; break;
                        default: break;
                    }
                    mu_input_mousedown(&ctx, e.button.x, e.button.y, btn);
                    break;
                }
                case SDL_MOUSEBUTTONUP: {
                    int btn = 0;
                    switch (e.button.button) {
                        case SDL_BUTTON_LEFT: btn = MU_MOUSE_LEFT; break;
                        case SDL_BUTTON_MIDDLE: btn = MU_MOUSE_MIDDLE; break;
                        case SDL_BUTTON_RIGHT: btn = MU_MOUSE_RIGHT; break;
                        default: break;
                    }
                    mu_input_mouseup(&ctx, e.button.x, e.button.y, btn);
                    break;
                }
                case SDL_MOUSEWHEEL:
                    mu_input_scroll(&ctx, e.wheel.x, e.wheel.y);
                    break;
                default:
                    break;
            }
        }

        mu_begin(&ctx);
        if (mu_begin_window(&ctx, "MicroUI Demo", mu_rect(40, 40, 320, 240))) {
            static const int row[] = { -1 };
            char click_text[48];

            mu_layout_row(&ctx, 1, row, 26);
            mu_label(&ctx, "SDL2 + OpenGL UI is running.");
            mu_layout_row(&ctx, 1, row, 30);
            if (mu_button(&ctx, "Click me"))
                clicks++;

            snprintf(click_text, sizeof(click_text), "Button clicks: %d", clicks);
            mu_layout_row(&ctx, 1, row, 26);
            mu_label(&ctx, click_text);
            mu_layout_row(&ctx, 1, row, 26);
            mu_checkbox(&ctx, "Enabled", &enabled);
            mu_layout_row(&ctx, 1, row, 26);
            mu_slider(&ctx, &slider, 0.0f, 1.0f);
        }
        mu_end_window(&ctx);
        mu_end(&ctx);

        r_clear(mu_color(0x30, 0x30, 0x30, 255));
        mu_Command *cmd = NULL;
        while (mu_next_command(&ctx, &cmd)) {
            if (cmd->type == MU_COMMAND_RECT)
                r_draw_rect(cmd->rect.rect, cmd->rect.color);
            else if (cmd->type == MU_COMMAND_TEXT)
                r_draw_text(cmd->text.str, cmd->text.pos, cmd->text.color);
            else if (cmd->type == MU_COMMAND_ICON)
                r_draw_icon(cmd->icon.id, cmd->icon.rect, cmd->icon.color);
            else if (cmd->type == MU_COMMAND_CLIP)
                r_set_clip_rect(cmd->clip.rect);
        }
        r_present();
    }

    SDL_Quit();
    return 0;
}