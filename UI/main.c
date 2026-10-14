#include <SDL2/SDL.h>
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
        return 1;
    }

    r_init();

    mu_Context ctx;
    mu_init(&ctx);
    ctx.text_width = ui_text_width;
    ctx.text_height = ui_text_height;

    int running = 1;
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
        // ... your UI code here ...
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