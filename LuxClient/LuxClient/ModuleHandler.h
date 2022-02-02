#pragma once

#include <algorithm>

#define PI 3.14159265359 // 3.14159265359

#include "Modules/AlwaysDay.h"
#include "Modules/Watermark.h"
#include "Modules/ArrayList.h"
#include "Modules/AutoSprint.h"
#include "Modules/Zoom.h"
#include "Modules/PlayerList.h"
#include "Modules/Notifications.h"
#include "Modules/CoordsHud.h"
#include "Modules/AutoSprint.h"


class ModuleHandler {
public:
    std::vector<Module*> modules;

public:

    struct CompareArg { bool operator()(Module* mod1, Module* mod2) { return mod1->name < mod2->name; } };

    void InitModules() {
        _logf(L"[Lux]: Registering modules...\n");

        // How to know what module goes where !
        std::string visual = "Visual"; // pvp stuff
        std::string hud = "Hud"; // world stuff
        std::string movement = "Movement"; // movements

        modules.push_back(new AlwaysDay(visual));
        modules.push_back(new Zoom(visual));

        modules.push_back(new ArrayList(hud));
        modules.push_back(new Notifications(hud));
        modules.push_back(new CoordsHud(hud));
        modules.push_back(new PlayerList(hud));
        modules.push_back(new Watermark(hud));

        modules.push_back(new AutoSprint(movement));
      
        // Sort modules
        std::sort(modules.begin(), modules.end(), CompareArg());

        _logf(L"[Lux]: Registered modules!\n");
    }

    void FrameRender(RenderUtils* ctx) {
        for (auto mod : modules)
            if (mod->enabled) {
                mod->OnFrameRender(ctx);
            }
    }
};