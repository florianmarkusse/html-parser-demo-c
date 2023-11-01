#include "html-example.h"

void readAndPrintHTML(flo_html_String fileLocation, flo_html_Arena scratch) {
    flo_html_Dom *dom = flo_html_createDomFromFile(fileLocation, &scratch);
    if (dom == NULL) {
        return;
    }

    printf("Before modification\n\n");
    flo_html_printHTML(dom);

    // Find the ID of the <body> element
    flo_html_node_id bodyNodeID = 0;
    if (flo_html_querySelector(FLO_HTML_S("body"), dom, &bodyNodeID, scratch) !=
        QUERY_SUCCESS) {
        fprintf(stderr, "Failed to query DOM!\n");
        return;
    }

    // Check if the body element has a specific boolean property
    // In other words: "<body add-extra-p-element> ... </body>"
    if (flo_html_hasBoolProp(bodyNodeID, FLO_HTML_S("add-extra-p-element"),
                             dom)) {
        // Append HTML content to the <body> element
        if (!flo_html_appendHTMLFromStringWithQuery(
                FLO_HTML_S("body"), FLO_HTML_S("<p>I am appended</p>"), dom,
                &scratch)) {
            fprintf(stderr, "Failed to append to DOM!\n");
            return;
        }
    }

    // Print the modified HTML
    printf("After modification\n\n");
    flo_html_printHTML(dom);
}
