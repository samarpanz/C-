#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CLAY_IMPLEMENTATION
#include "../clay/clay.h"
#include "../clay/renderers/raylib/clay_renderer_raylib.c"

static void HandleClayErrors(Clay_ErrorData errorData) {
	fprintf(stderr, "Clay error: %.*s\n", (int)errorData.errorText.length, errorData.errorText.chars);
}

int main(void) {
	Clay_Raylib_Initialize(800, 600, "Clay UI", FLAG_WINDOW_RESIZABLE);

	uint64_t clayRequiredMemory = Clay_MinMemorySize();
	void *memory = malloc((size_t)clayRequiredMemory);
	if (memory == NULL) {
		fprintf(stderr, "Could not allocate Clay memory.\n");
		Clay_Raylib_Close();
		return EXIT_FAILURE;
	}

	Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, memory);
	Clay_Initialize(clayMemory, (Clay_Dimensions) {
		.width = (float)GetScreenWidth(),
		.height = (float)GetScreenHeight()
	}, (Clay_ErrorHandler) { .errorHandlerFunction = HandleClayErrors, .userData = NULL });

	Font fonts[1] = { GetFontDefault() };
	Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

	while (!WindowShouldClose()) {
		Clay_SetLayoutDimensions((Clay_Dimensions) {
			.width = (float)GetScreenWidth(),
			.height = (float)GetScreenHeight()
		});

		Clay_BeginLayout();
		CLAY(CLAY_ID("Root"), {
			.layout = {
				.sizing = { CLAY_SIZING_GROW(0), CLAY_SIZING_GROW(0) },
				.padding = CLAY_PADDING_ALL(24),
				.childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
			},
			.backgroundColor = { 245, 247, 250, 255 }
		}) {
			CLAY_TEXT(CLAY_STRING("Hello from Clay"), {
				.fontSize = 32,
				.textColor = { 32, 39, 52, 255 }
			});
		}
		Clay_RenderCommandArray renderCommands = Clay_EndLayout(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);
		Clay_Raylib_Render(renderCommands, fonts);
		EndDrawing();
	}

	Clay_Raylib_Close();
	free(memory);
	return EXIT_SUCCESS;
}
