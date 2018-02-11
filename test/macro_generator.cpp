///*
// * Copyright 2017 Justas Masiulis
// *
// * Licensed under the Apache License, Version 2.0 (the "License");
// * you may not use this file except in compliance with the License.
// * You may obtain a copy of the License at
// *
// *     http://www.apache.org/licenses/LICENSE-2.0
// *
// * Unless required by applicable law or agreed to in writing, software
// * distributed under the License is distributed on an "AS IS" BASIS,
// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// * See the License for the specific language governing permissions and
// * limitations under the License.
// */
//
//#if CARBON_GENERATE_MACROS || 1
//#include <fstream>
//#include <string>
//
//std::string param(int i) { return "_" + std::to_string(i); }
//std::string expanded_param(int i) { return "#" + param(i); }
//std::string expand_args(int n, std::string prefix = {})
//{
//    std::string s;
//    for (int i = 0; i < n; ++i)
//        s += (prefix + "_" + std::to_string(i) + ',');
//    if (!s.empty())
//        s.pop_back();
//    return s;
//}
//
//int main()
//{
//    std::ofstream out("generated_macros.hpp");
//
//    out << "#pragma once\n"
//        << "#include <tuple>\n\n";
//
//    // generate [1, 32] serialization macros
//    for (int i = 1; i < 33; ++i) {
//        // macro definition
//        out << "#define CRBN_DETAIL_SERIALIZABLE_" << i << "(C";
//
//        for (int j = 0; j < i; ++j)
//            out << ",_" << j;
//        out << ")";
//
//        // macro body
//        out << "template<class _xCT, class _xCA> "
//            << "struct carbon_type {\\\n";
//        // archive ref
//        out << "\t_xCA& _archive_;\\\n";
//        // constructor
//        out << "\tcarbon_type(_xCA& a) : _archive_(a) {}\\\n";
//
//        // member pointers tuple
//        out << "\tconstexpr static auto member_pointers{std::make_tuple("
//            << expand_args(i, "&_xCT::") << ")};\\\n";
//
//
//        for (int j = 0; j < i; ++j) {
//            // functions to get the separate members
//            out << "\tdecltype(auto) " << param(j) << "()";
//            out << "{";
//            out << "return _this_->_xCT::" << param(j) << ";}\\\n";
//        }
//
//        out << "};\n";
//    }
//
//    out << "\n\n";
//
//    for (int i = 1; i < 33; ++i) {
//        out << "#define CRBN_DETAIL_NAMED_SERIALIZABLE_" << i << "(C";
//        for (int j = 0; j < i; ++j)
//            out << ",_" << j;
//        out << ") ::carbon::serializer<";
//        for (int j = 0; j < i; ++j) {
//            out << "::carbon::named_<CRBN_STR(#_" << j << ")"
//                << ",decltype(&C::_" << j << ")"
//                << ",&C::_" << j << '>';
//            if (j != i - 1)
//                out << ",";
//        }
//        out << ">;\n";
//    }
//}
//
//#endif
