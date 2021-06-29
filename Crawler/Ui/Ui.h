#ifndef  UI_H
#define  UI_H

#include "../Crawler/DocumentExtractor/DocumentExtractor.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

size_t getData(char* buffer, size_t itmsize, size_t itmcount, void* dest );
std::string Praser(const std::string& url);

std::string url = "file:///C:/Users/Lenovo/Desktop/WEB1.html";

#endif
