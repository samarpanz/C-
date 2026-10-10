#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CLAY_IMPLEMENTATION
#include "clay/clay.h"
#include "clay/renderers/raylib/clay_renderer_raylib.c"

static const Clay_Color COLOR_BACKGROUND = { 245, 247, 250, 255 };
static const Clay_Color COLOR_PANEL = { 255, 255, 255, 255 };
static const Clay_Color COLOR_ACCENT = { 39, 91, 160, 255 };
static const Clay_Color COLOR_TEXT = { 32, 39, 52, 255 };
static const Clay_Color COLOR_MUTED = { 105, 115, 130, 255 };

static void HandleClayErrors(Clay_ErrorData errorData) {
	fprintf(stderr, "Clay error: %.*s\n", (int) errorData.errorText.length, errorData.errorText.chars);
}

static Clay_RenderCommandArray CreateLayout(void) {
	Clay_BeginLayout();

	CLAY(CLAY_ID("App"), {
		.layout = {
			.layoutDirection = CLAY_TOP_TO_BOTTOM,
			.sizing = { CLAY_SIZING_GROW(0), CLAY_SIZING_GROW(0) },
			.padding = CLAY_PADDING_ALL(24),
			.childGap = 16
		},
		.backgroundColor = COLOR_BACKGROUND
	}) {
		CLAY(CLAY_ID("Header"), {
			.layout = {
				.sizing = { CLAY_SIZING_GROW(0), CLAY_SIZING_FIXED(64) },
				.childAlignment = { .y = CLAY_ALIGN_Y_CENTER },
				.padding = CLAY_PADDING_ALL(16)
			},
			.backgroundColor = COLOR_ACCENT
		}) {
			CLAY_TEXT(CLAY_STRING("My Application"), {
				.fontSize = 24,
				.textColor = (Clay_Color) { 255, 255, 255, 255 }
			});
		}

		CLAY(CLAY_ID("Body"), {
			.layout = {
				.sizing = { CLAY_SIZING_GROW(0), CLAY_SIZING_GROW(0) },
				.childGap = 16
			}
		}) {
			CLAY(CLAY_ID("Sidebar"), {
				.layout = {
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
					.sizing = { CLAY_SIZING_FIXED(180), CLAY_SIZING_GROW(0) },
					.padding = CLAY_PADDING_ALL(16),
					.childGap = 12
				},
				.backgroundColor = COLOR_PANEL
			}) {
				CLAY_TEXT(CLAY_STRING("Navigation"), {
					.fontSize = 16,
					.textColor = COLOR_MUTED
				});
				CLAY_TEXT(CLAY_STRING("Dashboard"), {
					.fontSize = 18,
					.textColor = COLOR_ACCENT
				});
				CLAY_TEXT(CLAY_STRING("Settings"), {
					.fontSize = 18,
					.textColor = COLOR_TEXT
				});
			}

			CLAY(CLAY_ID("Content"), {
				.layout = {
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
					.sizing = { CLAY_SIZING_GROW(0), CLAY_SIZING_GROW(0) },
					.padding = CLAY_PADDING_ALL(24),
					.childGap = 12
				},
				.backgroundColor = COLOR_PANEL
			}) {
				CLAY_TEXT(CLAY_STRING("Dashboard"), {
					.fontSize = 28,
					.textColor = COLOR_TEXT
				});
				CLAY_TEXT(CLAY_STRING("Welcome to your basic Clay UI layout."), {
					.fontSize = 16,
					.textColor = COLOR_MUTED
				});
			}
		}

		CLAY(CLAY_ID("Footer"), {
			.layout = {
				.sizing = { CLAY_SIZING_GROW(0), CLAY_SIZING_FIXED(32) },
				.childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
			}
		}) {
			CLAY_TEXT(CLAY_STRING("Status: ready"), {
				.fontSize = 14,
				.textColor = COLOR_MUTED
			});
		}
	}

	return Clay_EndLayout(0.0f);
}

int main(void) {
	const int initialWidth = 1024;
	const int initialHeight = 700;
	Clay_Raylib_Initialize(initialWidth, initialHeight, "Clay Basic UI", FLAG_WINDOW_RESIZABLE);

	const uint64_t memorySize = Clay_MinMemorySize();
	void *memory = malloc((size_t) memorySize);
	if (memory == NULL) {
		fprintf(stderr, "Could not allocate Clay memory.\n");
		Clay_Raylib_Close();
		return EXIT_FAILURE;
	}

	Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(memorySize, memory);
	Clay_Initialize(arena, (Clay_Dimensions) { initialWidth, initialHeight }, (Clay_ErrorHandler) {
		.errorHandlerFunction = HandleClayErrors,
		.userData = NULL
	});

	Font fonts[1] = { GetFontDefault() };
	Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

	while (!WindowShouldClose()) {
		const float deltaTime = GetFrameTime();
		Clay_SetLayoutDimensions((Clay_Dimensions) {
			(float) GetScreenWidth(),
			(float) GetScreenHeight()
		});
		Clay_SetPointerState((Clay_Vector2) {
			(float) GetMouseX(),
			(float) GetMouseY()
		}, IsMouseButtonDown(MOUSE_BUTTON_LEFT));
		Clay_UpdateScrollContainers(true, (Clay_Vector2) { 0, GetMouseWheelMove() }, deltaTime);

		Clay_RenderCommandArray commands = CreateLayout();

		BeginDrawing();
		ClearBackground(RAYWHITE);
		Clay_Raylib_Render(commands, fonts);
		EndDrawing();
	}

	Clay_Raylib_Close();
	free(memory);
	return EXIT_SUCCESS;
}
