-- Entities that test their callbacks

local message = function(msg)
	minetest.log("action", msg)
	minetest.chat_send_all(msg)
end

local get_object_name = function(obj)
	local name = "<nil>"
	if obj then
		if obj:is_player() then
			name = obj:get_player_name()
		else
			name = "<entity>"
		end
	end
	return name
end

local spos = function(self)
	return minetest.pos_to_string(vector.round(self.object:get_pos()))
end

-- Callback test entity (all callbacks except on_step)
minetest.register_entity("testentities:callback", {
	initial_properties = {
		visual = "upright_sprite",
		textures = { "testentities_callback.png" },
	},

	on_activate = function(self, staticdata, dtime_s)
		message("Callback entity: on_activate! pos="..spos(self).."; dtime_s="..dtime_s)
	end,
	on_deactivate = function(self)
		message("Callback entity: on_deactivate! pos="..spos(self))
	end,
	on_punch = function(self, puncher, time_from_last_punch, tool_capabilities, dir, damage)
		local name = get_object_name(puncher)
		message(
			"Callback entity: on_punch! "..
			"pos="..spos(self).."; puncher="..name.."; "..
			"time_from_last_punch="..time_from_last_punch.."; "..
			"tool_capabilities="..tostring(dump(tool_capabilities)).."; "..
			"dir="..tostring(dump(dir)).."; damage="..damage)
	end,
	on_rightclick = function(self, clicker)
		local name = get_object_name(clicker)
		message("Callback entity: on_rightclick! pos="..spos(self).."; clicker="..name)
	end,
	on_death = function(self, killer)
		local name = get_object_name(killer)
		message("Callback entity: on_death! pos="..spos(self).."; killer="..name)
	end,
	on_attach_child = function(self, child)
		local name = get_object_name(child)
		message("Callback entity: on_attach_child! pos="..spos(self).."; child="..name)
	end,
	on_detach_child = function(self, child)
		local name = get_object_name(child)
		message("Callback entity: on_detach_child! pos="..spos(self).."; child="..name)
	end,
	on_detach = function(self, parent)
		local name = get_object_name(parent)
		message("Callback entity: on_detach! pos="..spos(self).."; parent="..name)
	end,
	get_staticdata = function(self)
		message("Callback entity: get_staticdata! pos="..spos(self))
	end,
})

-- Only test on_step callback
minetest.register_entity("testentities:callback_step", {
	visual = "upright_sprite",
	textures = { "testentities_callback_step.png" },
	on_step = function(self, dtime)
		message("on_step callback entity: on_step! pos="..spos(self).."; dtime="..dtime)
	end,
})
