#include <flo/html-parser.h>

#include "html-example.h"

int main() {
    flo_html_Arena arena = flo_html_newArena(1U << 27U);
    void *jmp_buf[5];
    if (__builtin_setjmp(jmp_buf)) {
        flo_html_destroyArena(&arena);
        FLO_HTML_PRINT_ERROR("OOM in arena!\n");
        return 1;
    }
    arena.jmp_buf = jmp_buf;
    // Read and print the html-test file.
    readAndPrintHTML(FLO_HTML_S("src/html-test.html"), arena);

    // Operating system automatically cleans up allocated memory.
    return 0;
}
