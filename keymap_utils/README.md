DMCP Development Manual
=======================

About this Development Manual
-----------------------------

This document refers to special procedures and facts related to DMCP development and testing.

General Information
-------------------

### Key representation in this document

`xx` represents the key xx under current system key table

`xx/RC` represents the key xx on original DM42 keyboard at row R and column C, e.g. `F1/11`, `F6/16`

### System key table

System key table is used to map hardware layout of keys to independent codes to ensure DMCP is able to directly use keys (like numbers, arrows etc.).

Keyboard routines are thus extended to read keys by codes or row/col placements.

#### Update

*   Copy KEYMAP.BIN to root directory of calc flash disk
    
*   Keymap is automatically installed after ejecting the calc disk from PC
    

#### Recovery to required keymap

This method uses only bottom right key (`+/85` on DM42) to enter MSC mode. So, no other keys are needed.

*   press RESET+`+/85` which unconditionally enters MSC mode
    
*   Copy KEYMAP.BIN to root directory of calc flash disk
    
*   Keymap is automatically installed after ejecting the calc disk from PC and calculator is RESET.
    

#### Creating new keymap

The file `/keymaps/empty/keymap.bin` is empty keymap for recovery of original settings.

Use following steps to create new `keymap.bin` file:

1.  Take `/keymaps/base/keymap.txt` and swap positions of key codes in this file
    
2.  Check the layout by running
    
        keymap2layout keymap.txt
    
    which should display the layout in terms of original key names.
    
3.  Generate new keymap.bin using
    
        mk_keymap <KEYID> keymap.txt
    
    where `<KEYID>` is short keymap identifier (max 8 chars).
    

### Special RESET key combinations

This chapter describes special actions invoked when some keys are pressed during calc reset.

Table RESET keys    

| Keys        | Handles | Action                        | Note                                                                                                                               |
|-------------|---------|-------------------------------|------------------------------------------------------------------------------------------------------------------------------------|
| RESET+`−`     | PGM     | Clean Reset                   | DM42 doesn't load calculator state starting with 'Memory Clear' message                                                      |
| RESET+`F1/11` | DMCP    | DMCP Menu                     | Jump to DMCP menu instead of starting program                                                                                      |
| RESET+`F6/16` | DMCP    | Production diagnostics screen | Jump directly to keyboard test of diagnostics screen. Use `EXIT/81`+`F6/16` to leave keyboard test and enter diagnostics menu.       |
| RESET+`+/85`  | DMCP    | MSC Mode                      | Jump directly to USB MSC mode. After ending MSC mode by PC usual check for fw and keymap update is done. Then the calc is RESET. |

