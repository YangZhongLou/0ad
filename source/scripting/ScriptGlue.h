
#ifndef _SCRIPTGLUE_H_
#define _SCRIPTGLUE_H_

#include "ScriptingHost.h"

typedef JSBool JSFunc(JSContext* /*context*/, JSObject* /*globalObject*/, unsigned int /*argc*/, jsval* /*argv*/, jsval* /*rval*/);

// Functions to be called from Javascript:

JSFunc WriteLog;

// Entity
JSFunc getEntityByHandle;
JSFunc getEntityTemplate;
JSBool GetEntitySet( JSContext* context, JSObject* globalObject, jsval id, jsval* vp );

// Player
JSBool GetPlayerSet( JSContext* context, JSObject* globalObject, jsval id, jsval* vp );
JSBool GetLocalPlayer( JSContext* context, JSObject* globalObject, jsval id, jsval* vp );
JSBool SetLocalPlayer( JSContext* context, JSObject* globalObject, jsval id, jsval* vp );
JSBool GetGaiaPlayer( JSContext* context, JSObject* globalObject, jsval id, jsval* vp );
// JSBool SetGaiaPlayer( JSContext* context, JSObject* globalObject, jsval argv, jsval* vp );

// Events system
JSFunc AddGlobalHandler;
JSFunc RemoveGlobalHandler;

// Camera
JSFunc setCameraTarget;

// Timer
JSFunc setTimeout;
JSFunc setInterval;
JSFunc cancelInterval;

// Debug
JSBool forceGC( JSContext* context, JSObject* globalObject, unsigned int argc, jsval* argv, jsval* rval );

// Returns the sort-of-global object associated with the current GUI
JSFunc getGUIGlobal;

// Returns the global object, e.g. for setting global variables.
JSFunc getGlobal;

JSFunc setCursor;

JSFunc GetGameObject;
JSFunc createServer;
JSFunc createClient;
JSFunc startGame;
JSFunc endGame;

// Replaces the current language (locale) with a new one
JSFunc loadLanguage;

// Returns the current language's name, in the same form as passed to loadLanguage
JSFunc getLanguageID;

JSFunc getFPS;
JSFunc getCursorPosition;
JSFunc v3dist;

// Returns a string that says when ScriptGlue.cpp was last recompiled
JSFunc buildTime;

// Tells the main loop to stop looping
JSFunc exitProgram;

// Crashes.
JSFunc crash;

// Tries to print the amount of remaining video memory.
JSFunc vmem;

// You don't want to use this
JSFunc _rewriteMaps;

extern JSFunctionSpec ScriptFunctionTable[];
extern JSPropertySpec ScriptGlobalTable[];

#endif
