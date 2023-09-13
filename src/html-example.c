#include <flo/html-parser.h>
#include <stdio.h>

#include "html-example.h"

void readAndPrintHTML(const char *fileLocation) {
    // Initialize a text store to manage memory
    TextStore textStore;
    if (createTextStore(&textStore) != ELEMENT_SUCCESS) {
        fprintf(stderr, "Failed to create text store!\n");
        return;
    }

    // Initialize a DOM structure
    Dom dom;
    if (createDomFromFile(fileLocation, &dom, &textStore) != DOM_SUCCESS) {
        destroyTextStore(&textStore);
        fprintf(stderr, "Failed to parse DOM from file!\n");
        return;
    }

    // Print before modification.
    printf("Before modification\n\n");
    printHTML(&dom, &textStore);

    // Find the ID of the <body> element
    node_id bodyNodeID = 0;
    if (querySelector("body", &dom, &textStore, &bodyNodeID) != QUERY_SUCCESS) {
        destroyDom(&dom);
        destroyTextStore(&textStore);
        fprintf(stderr, "Failed to query DOM!\n");
        return;
    }

    // Check if the body element has a specific boolean property
    // In other words: "<body add-extra-p-element> ... </body>"
    if (hasBoolProp(bodyNodeID, "add-extra-p-element", &dom, &textStore)) {
        // Append HTML content to the <body> element
        if (appendHTMLFromStringWithQuery("body", "<p>I am appended</p>", &dom,
                                          &textStore) != DOM_SUCCESS) {
            destroyDom(&dom);
            destroyTextStore(&textStore);
            fprintf(stderr, "Failed to append to DOM!\n");
            return;
        }
    }

    // Print the modified HTML
    printf("After modification\n\n");
    printHTML(&dom, &textStore);

    // Cleanup: Free memory and resources
    destroyDom(&dom);
    destroyTextStore(&textStore);
}
