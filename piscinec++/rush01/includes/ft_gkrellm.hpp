#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <gtk/gtk.h>
# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <map>
# include <cstdlib>
# include <unistd.h>
# include <ncurses.h>
# include <time.h>
# include <algorithm>

class IMonitorModule;
class AModuleGraph;
class NWindow;
class GTKDisplay;

typedef std::map< char, bool > Options;
typedef std::list< std::string > StringList;
typedef std::list< int > IntList;
typedef std::list< IntList > GraphList;
typedef std::list< IMonitorModule * > ModuleList;

Options				getOptions(int ac, char **av);
void				printHelp(void);
ModuleList			fillModules(Options option);

class Position;


# include "Position.Class.hpp"
# include "IMonitorModule.Class.hpp"
# include "IMonitorDisplay.Class.hpp"
# include "AModuleGraph.Class.hpp"
# include "Nwindow.Class.hpp"
# include "NcursesDisplay.Class.hpp"
# include "ModuleHostname.Class.hpp"
# include "GTKDisplay.Class.hpp"

typedef std::list< IMonitorModule * > ModuleList;

#endif
