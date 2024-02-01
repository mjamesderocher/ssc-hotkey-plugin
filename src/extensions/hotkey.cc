#include <socket/extension.h>
#include <Cocoa/Cocoa.h>

// Global variables
id eventMonitor = nil;

// Callback function for handling hotkey events
void handleHotKeyEvent(NSEvent *event) {
    if (([event modifierFlags] & NSEventModifierFlagCommand) && ([event keyCode] == 40)) {
        // Handle the hotkey event (Cmd + K)
        printf("Cmd + K pressed\n");
    }
}

bool initialize (sapi_context_t* context, const void* data) {
  @autoreleasepool {
    // Create and add a global monitor for key events
    eventMonitor = [NSEvent addGlobalMonitorForEventsMatchingMask:NSEventMaskKeyDown handler:^(NSEvent *event){
        handleHotKeyEvent(event);
    }];

    // Run the application
    [[NSRunLoop currentRunLoop] run];
  }

  return true;
}

bool deinitialize (sapi_context_t* context, const void *data) {
  return true;
}

SOCKET_RUNTIME_REGISTER_EXTENSION(
  "hotkey", // name
  initialize, // initializer
  deinitialize, // deinitializer
  "an extension that listens to cmd + k", // description
  "0.1.2" // version
);