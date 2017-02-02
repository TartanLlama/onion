/*
	Onion HTTP server library
	Copyright (C) 2010-2015 David Moreno Montero and others

	This library is free software; you can redistribute it and/or
	modify it under the terms of, at your choice:
	
	a. the Apache License Version 2.0. 
	
	b. the GNU General Public License as published by the 
		Free Software Foundation; either version 2.0 of the License, 
		or (at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of both libraries, if not see 
	<http://www.gnu.org/licenses/> and 
	<http://www.apache.org/licenses/LICENSE-2.0>.
	*/

#pragma once

namespace Onion{
    class Websocket{
        onion_websocket *ptr;
    public:
        std::string read() {
            
        }
        
        void write(const std::string& str) {
            onion_websocket_write(ptr, str.c_str(), str.size());
        }

        template <typename... Args>
        void printf(const std::string& fmt, Args&&... args) {
            onion_websocket_printf(ptr, std::forward<Args>(args)...);
        }

        template <typename F>
        void setCallback(F&& f);

        void setOpcode(onion_websocket_opcode opcode);
        onion_websocket_opcode getOpcode();

        onion_websocket *c_handler() { return ptr; }
    };
};
