/*
show_clearsign.h
OpenPGP exectuable module

Copyright (c) 2013 - 2017 Jason Lee @ calccrypto@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __COMMAND_SHOW_CLEARSIGN__
#define __COMMAND_SHOW_CLEARSIGN__

#include "../../OpenPGP.h"
#include "module.h"

namespace module {

const Module show_clearsign(
    // name
    "show-clearsign",

    // positional arguments
    {
        "file",
    },

    // optional arugments
    {
        std::make_pair("o", std::make_pair("output file", "")),
    },

    // function to run
    [](std::map <std::string, std::string> & args) -> int {
        std::ifstream f(args.at("file"), std::ios::binary);
        if (!f){
            std::cerr << "Error: File '" + args.at("filename") + "' not opened." << std::endl;
            return -1;
        }

        PGPMessage msg(f);

        output(msg.show(), args.at("o"));

        return 0;
    }
);

}

#endif