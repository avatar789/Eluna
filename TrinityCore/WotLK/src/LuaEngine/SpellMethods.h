/* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SPELLMETHODS_H
#define SPELLMETHODS_H

class LuaSpell
{
public:
    // :GetUnitType()
    static int GetUnitType(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        lua_pushstring(L, "Spell");
        return 1;
    }

    // GetCaster()
    static int GetCaster(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        sEluna->PushUnit(L, spell->GetCaster());
        return 1;
    }

    // GetCastTime()
    static int GetCastTime(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        sEluna->PushInteger(L, spell->GetCastTime());
        return 1;
    }

    // GetId()
    static int GetId(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        sEluna->PushUnsigned(L, spell->GetSpellInfo()->Id);
        return 1;
    }

    // GetPowerCost()
    static int GetPowerCost(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        sEluna->PushInteger(L, spell->GetPowerCost());
        return 1;
    }

    // GetDuration()
    static int GetDuration(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        sEluna->PushInteger(L, spell->GetSpellInfo()->GetDuration());
        return 1;
    }

    // Cast(skipCheck)
    static int Cast(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        bool skipCheck = lua_toboolean(L, 1);
        spell->cast(skipCheck);
        return 0;
    }

    //IsAutoRepeat()
    static int IsAutoRepeat(lua_State* L, Spell* spell)
    {
        if (!spell)
            sEluna->PushBoolean(L, false);
        else
        {
            bool repeat = spell->IsAutoRepeat();
            sEluna->PushBoolean(L, repeat);
        }
        return 1;
    }

    //SetAutoRepeat(boolean)
    static int SetAutoRepeat(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        bool repeat = luaL_checkbool(L, 1);
        spell->SetAutoRepeat(repeat);
        return 0;
    }

    // Cancel()
    static int cancel(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        spell->cancel();
        return 0;
    }

    // Finish()
    static int Finish(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        spell->finish();
        return 0;
    }

    // GetTargetDest()
    static int GetTargetDest(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        if (!spell->m_targets.HasDst())
            return 0;
        float x, y, z, o;
        spell->m_targets.GetDstPos()->GetPosition(x,y,z,o);
        sEluna->PushFloat(L, x);
        sEluna->PushFloat(L, y);
        sEluna->PushFloat(L, z);
        sEluna->PushFloat(L, o);
        sEluna->PushUnsigned(L, spell->m_targets.GetDstPos()->GetMapId());
        return 5;
    }
};
#endif