/*

readline.h

is part of:

WinEditLine (formerly MinGWEditLine)
Copyright 2010-2016 Paolo Tosco <paolo.tosco.mail@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of WinEditLine (formerly MinGWEditLine) nor the
    name of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#ifndef _READLINE_H_
#define _READLINE_H_

#include <windows.h>

#if defined(_USRDLL)
  #if defined(readline_EXPORTS)
    #define READLINE_ABI __declspec(dllexport)
  #else
    #define READLINE_ABI __declpsec(dllimport)
  #endif
#else
  #define READLINE_ABI
#endif

/*
these defines may be changed
*/
#define DEFAULT_HISTORY_SIZE    200  /* default number of history entries */

typedef char **rl_completion_func_t(const char *, int, int);
typedef char *rl_compentry_func_t(const char *, int);
typedef void rl_compentryfree_func_t(void *);
/*
this is ignored by WinEditLine
*/
typedef void *histdata_t;

typedef struct _hist_entry {
  char *line;
  char *timestamp;
  histdata_t data;
} HIST_ENTRY;

typedef struct _hist_state {
  HIST_ENTRY **entries;
  int offset;
  int length;
  int size;
  int flags;
} HISTORY_STATE;


/*
prototypes of functions which may be
called by the user
*/
READLINE_ABI
void source_editrc(void);

READLINE_ABI
char *readline(const char *prompt);

READLINE_ABI
char **rl_completion_matches(const char *text, char *entry_func(const char *, int));

READLINE_ABI
char *rl_filename_completion_function(const char *text, int state);

READLINE_ABI
void rl_free(void *mem);

READLINE_ABI
int using_history(void);

READLINE_ABI
void free_history(void);

READLINE_ABI
void free_history_entry(HIST_ENTRY *entry);

READLINE_ABI
void clear_history(void);

READLINE_ABI
char *add_history(char *line);

READLINE_ABI
HIST_ENTRY *remove_history(int i);

READLINE_ABI
HIST_ENTRY *replace_history_entry(int i, char *line, histdata_t dummy);

READLINE_ABI
HIST_ENTRY **history_list(void);

READLINE_ABI
int where_history(void);

READLINE_ABI
int history_length(void);

READLINE_ABI
HIST_ENTRY *current_history(void);

READLINE_ABI
HIST_ENTRY *history_get(int offset);

READLINE_ABI
int history_set_pos(int i);

READLINE_ABI
HIST_ENTRY *previous_history(void);

READLINE_ABI
HIST_ENTRY *next_history(void);

READLINE_ABI
int read_history(const char *filename);

READLINE_ABI
int write_history(const char *filename);

READLINE_ABI
int append_history(int nelements, const char *filename);

READLINE_ABI
int history_truncate_file(const char *filename, int nlines);

/*
extern variables
*/
extern READLINE_ABI
char *rl_line_buffer;

extern READLINE_ABI
char *rl_prompt;

extern READLINE_ABI
int rl_point;

extern READLINE_ABI
int rl_attempted_completion_over;

extern READLINE_ABI
int rl_completion_append_character;

extern READLINE_ABI
const char rl_basic_word_break_characters[];

extern READLINE_ABI
const char *rl_completer_word_break_characters;

extern READLINE_ABI
const char *rl_readline_name;

extern READLINE_ABI
rl_completion_func_t *rl_attempted_completion_function;

extern READLINE_ABI
rl_compentry_func_t *rl_completion_entry_function;

extern READLINE_ABI
rl_compentryfree_func_t *rl_user_completion_entry_free_function;

#ifdef __cplusplus
}
#endif

#endif /* _READLINE_H_ */
