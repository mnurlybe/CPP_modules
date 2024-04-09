/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:37:27 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/09 17:21:53 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4){
        std::cerr << "wrong number of arguments" << std::endl;
        return 1;
    }

    std::string src_filename = argv[1];
    std::string dst_filename = src_filename + ".replace";
    std::string substr_old = argv[2];
    std::string substr_new = argv[3];

    if (substr_old.empty() && !substr_new.empty())
    {
        std::cerr << "wrong input" << std::endl;
        return 1;
    }
    
    // opening source file
    std::ifstream srcfile(src_filename.c_str());
    if (!srcfile.is_open())
    {
        std::cerr << "Error openning file: " << src_filename << std::endl;
        return 1;
    }
    // creating destination file
    std::ofstream dstfile(dst_filename.c_str());
    if (!dstfile.is_open())
    {
        std::cerr << "Error creating file: " << dst_filename << std::endl;
        return 1;
    }
    
    std::string line;
    std::string newline;
    
    std::cerr << "HERE" << std::endl;
    if (!std::getline(srcfile, line, '\0'))
    {
        std::cerr << "File is empty" << std::endl;
        return 1;
    }

    newline += line;
    size_t pos = newline.find(substr_old);
    while (pos != std::string::npos){
        newline.erase(pos, substr_old.length());
        newline.insert(pos, substr_new);
        pos = newline.find(substr_old, pos + 1);
    }
    dstfile << newline;
    newline.clear();
    
    srcfile.close();
    dstfile.close();
    return 0;
}
