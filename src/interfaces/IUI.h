#pragma once

class IUI {
    public:
        virtual ~IUI() = default;
        virtual void DisplayGameConfiguration() = 0;
};