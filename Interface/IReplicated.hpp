
#pragma once

class IReplicated
{
    virtual void Create() = 0;
    virtual void Update() = 0;
    virtual void OnUpdate() = 0;
    virtual void Destroy() = 0;
};