####
#
#	Truth Table Generator Makefile
#	by Equilibrium
#
#	equilibriumtr@gmail.com
#
#	ayberkozgur.blogspot.com
#
#	Modified 14. Feb. 218
#	by Mingyun Kim
#	mikim@student.42.us.org
#	https://github.com/mikim42
#
####

#Project name
PROJECT = ttgen

#Project specific environment variables
COMPILE = g++
LINK = g++
MKDIR = mkdir -p
RM = rm -f -r
CP = cp -f

#Directories
SRCDIR = src
OBJDIR = build
BINDIR = bin

#Object file list
OBJFILES = $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(wildcard $(SRCDIR)/*.cpp))

#Compiler flags
CFLAGS = -c -O2 -Wall

#Linker flags
LFLAGS = 

#Default target
all: $(BINDIR)/$(PROJECT)
	@echo "$(PROJECT): Successfully built all."
	
#Main target of project
$(BINDIR)/$(PROJECT): $(OBJFILES)
	@echo "$(PROJECT): Linking $@..."
	@$(MKDIR) $(BINDIR)
	@$(LINK) $(OBJFILES) -o $@
	@echo "$(PROJECT): Successfully linked $@."
	
#Object targets of project
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	@echo "$(PROJECT): Building $@..."
	@$(MKDIR) $(OBJDIR)
	@$(COMPILE) $< $(CFLAGS) -o $@
	@echo "$(PROJECT): Successfully built $@."

#Cleaner target
clean:
	@echo "$(PROJECT): Cleaning..."
	@$(RM) $(OBJDIR)
	@$(RM) $(BINDIR)
	@echo "$(PROJECT): Successfully cleaned project."

#Installer target
install: all
	@echo "$(PROJECT): Installing..."
	@$(CP) $(BINDIR)/$(PROJECT) $(HOME)/bin/
	@echo "$(PROJECT): Installed successfully."
	
#Uninstaller target
uninstall:
	@echo "$(PROJECT): Uninstalling..."
	@$(RM) $(HOME)/bin/$(PROJECT)
	@echo "$(PROJECT): Uninstalled successfully."
	
