/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:37:27 by mnurlybe          #+#    #+#             */
/*   Updated: 2024/04/09 18:15:19 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

    if (substr_old.empty())
    {
        std::cerr << "wrong input: First string is empty" << std::endl;
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
    
    std::stringstream WholeFile;
    WholeFile << srcfile.rdbuf();
    std::string whole_text = WholeFile.str();

    if (!whole_text.length())
    {
        std::cerr << "File is empty" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < whole_text.length(); i++)
    {
        if (whole_text.substr(i).find(substr_old) == 0)
        {
            i += substr_old.length() - 1;
            dstfile << substr_new;
        }
        else
            dstfile << whole_text[i];
    }
    
    srcfile.close();
    dstfile.close();
    return 0;
}
