/*
Minetest
Copyright (C) 2013 celeron55, Perttu Ahola <celeron55@gmail.com>
Copyright (C) 2017 nerzhul, Loic Blot <loic.blot@unix-experience.fr>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once

#include "lua_api/l_base.h"
#include "itemdef.h"
#include "tool.h"
#include "lua_api/l_object.h"
#include "client/gameui.h"

class ModApiClient : public ModApiBase
{
private:
	// get_current_modname()
	static int l_get_current_modname(lua_State *L);

	// get_modpath(modname)
	static int l_get_modpath(lua_State *L);

	// print(text)
	static int l_print(lua_State *L);

	// display_chat_message(message)
	static int l_display_chat_message(lua_State *L);

	// send_chat_message(message)
	static int l_send_chat_message(lua_State *L);

	// clear_out_chat_queue()
	static int l_clear_out_chat_queue(lua_State *L);

	// get_player_names()
	static int l_get_player_names(lua_State *L);

	// show_formspec(name, formspec)
	static int l_show_formspec(lua_State *L);

	// send_respawn()
	static int l_send_respawn(lua_State *L);

	// disconnect()
	static int l_disconnect(lua_State *L);

	// gettext(text)
	static int l_gettext(lua_State *L);

	// get_last_run_mod(n)
	static int l_get_last_run_mod(lua_State *L);

	// set_last_run_mod(modname)
	static int l_set_last_run_mod(lua_State *L);

	// get_node(pos)
	static int l_get_node_or_nil(lua_State *L);

	// get_language()
	static int l_get_language(lua_State *L);

	// get_wielded_item()
	static int l_get_wielded_item(lua_State *L);

	// get_meta(pos)
	static int l_get_meta(lua_State *L);

	// sound_play(spec, parameters)
	static int l_sound_play(lua_State *L);

	// sound_stop(handle)
	static int l_sound_stop(lua_State *L);

	// sound_fade(handle, step, gain)
	static int l_sound_fade(lua_State *L);

	// get_server_info()
	static int l_get_server_info(lua_State *L);

	// get_item_def(itemstring)
	static int l_get_item_def(lua_State *L);

	// get_node_def(nodename)
	static int l_get_node_def(lua_State *L);

	// get_privilege_list()
	static int l_get_privilege_list(lua_State *L);

	// get_builtin_path()
	static int l_get_builtin_path(lua_State *L);

	// get_csm_restrictions()
	static int l_get_csm_restrictions(lua_State *L);

	static int l_set_ignore_timeofday(lua_State *L);

	static int l_set_ignore_fov(lua_State *L);

	static int l_set_ignore_hp(lua_State *L);

	static int l_set_ignore_breath(lua_State *L);

	static int l_set_ignore_death_screen(lua_State *L);

	static int l_set_ignore_spawn_particle(lua_State *L);

	static int l_set_ignore_add_particle_spawner(lua_State *L);

	static int l_set_ignore_set_sky(lua_State *L);

	static int l_set_ignore_zoom(lua_State *L);

	static int l_set_ignore_override_daynightratio(lua_State *L);

	static int l_get_cao_by_name(lua_State *L);

	static int l_close_formspec(lua_State *L);

	static int l_send_damage(lua_State *L);

	static int l_dig_node(lua_State *L);

	static int l_use_on(lua_State *L);

	static int l_activate_node(lua_State *L);

	static int l_place_node(lua_State *L);

	static int l_set_timeofday(lua_State* L);

public:
	static void Initialize(lua_State *L, int top);
};
