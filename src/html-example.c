#include <flo/html-parser.h>
#include <stdio.h>

#include "html-example.h"

void readAndPrintHTML(const char *fileLocation) {
    // Initialize a text store to manage memory
    flo_html_TextStore textStore;
    if (flo_html_createTextStore(&textStore) != ELEMENT_SUCCESS) {
        fprintf(stderr, "Failed to create text store!\n");
        return;
    }

    // Initialize a DOM structure
    flo_html_Dom dom;
    if (flo_html_createDomFromFile(fileLocation, &dom, &textStore) !=
        DOM_SUCCESS) {
        flo_html_destroyTextStore(&textStore);
        fprintf(stderr, "Failed to parse DOM from file!\n");
        return;
    }

    // Print before modification.
    printf("Before modification\n\n");
    flo_html_printHTML(&dom, &textStore);

    // Find the ID of the <body> element
    flo_html_node_id bodyNodeID = 0;
    if (flo_html_querySelector("body", &dom, &textStore, &bodyNodeID) !=
        QUERY_SUCCESS) {
        flo_html_destroyDom(&dom);
        flo_html_destroyTextStore(&textStore);
        fprintf(stderr, "Failed to query DOM!\n");
        return;
    }

    // Check if the body element has a specific boolean property
    // In other words: "<body add-extra-p-element> ... </body>"
    if (flo_html_hasBoolProp(bodyNodeID, "add-extra-p-element", &dom,
                             &textStore)) {
        // Append HTML content to the <body> element
        if (flo_html_appendHTMLFromStringWithQuery("body",
                                                   "<p>I am appended</p>", &dom,
                                                   &textStore) != DOM_SUCCESS) {
            flo_html_destroyDom(&dom);
            flo_html_destroyTextStore(&textStore);
            fprintf(stderr, "Failed to append to DOM!\n");
            return;
        }
    }

    // Print the modified HTML
    printf("After modification\n\n");
    flo_html_printHTML(&dom, &textStore);

    // Cleanup: Free memory and resources
    flo_html_destroyDom(&dom);
    flo_html_destroyTextStore(&textStore);
}
