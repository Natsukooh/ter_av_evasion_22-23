cmake_minimum_required(VERSION 3.23.2)

project(av_evasion_ter_22-23 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the static linking flags
set(CMAKE_EXE_LINKER_FLAGS "-static")

# Set the source file
set(SOURCE_FILE src/no_obfuscation/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/calc.hpp
        src/shellcodes/unstaged_meterpreter_reverse_shell.hpp
        src/shellcodes/staged_meterpreter_reverse_shell.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # Create an executable for the current shellcode
    # The executable must have the name of the shellcode but preceding it with "unobfuscated_"
    add_executable(unobfuscated_${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "unobfuscated_" and ending with "_debug"
    add_executable(unobfuscated_${SHELLCODE_NAME}_debug ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(unobfuscated_${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(unobfuscated_${SHELLCODE_NAME}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(unobfuscated_${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(unobfuscated_${SHELLCODE_NAME}_debug PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()

# now let's do the same for the executable src/technique_1_encrypting_shellcode/sheellcode_dropper.cpp
# Set the source file
set(SOURCE_FILE src/technique_1_encrypting_shellcode/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/xored_calc.hpp
        src/shellcodes/xored_unstaged_meterpreter_reverse_shell.hpp
        src/shellcodes/xored_staged_meterpreter_reverse_shell.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # rename the currect SHELLCODE_NAME to remove the "xored_" prefix
    string(REGEX REPLACE "xored_(.*)" "\\1" SHELLCODE_NAME ${SHELLCODE_NAME})

    # Create an executable for the current shellcode
    # The executable must have the name of the shellcode but preceding it with "xored_"
    add_executable(xored_${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "xored_" and ending with "_debug"
    add_executable(xored_${SHELLCODE_NAME}_debug ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(xored_${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(xored_${SHELLCODE_NAME}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(xored_${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(xored_${SHELLCODE_NAME}_debug PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()

# now let's do the same for the executable src/technique_2_reducing_entropy/shellcode_dropper.cpp
# Set the source file
set(SOURCE_FILE src/technique_2_reducing_entropy/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/natural_language_calc.hpp
        src/shellcodes/natural_language_staged_meterpreter_reverse_shell.hpp
        src/shellcodes/natural_language_staged_reverse_shell.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # Create an executable for the current shellcode
    # The executable's name should be "low_entropy_" + the shellcode name
    add_executable(${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "debug_"
    add_executable(debug_${SHELLCODE_NAME} ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(debug_${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(debug_${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()

set(SOURCE_FILE src/technique_2bis_reducing_entropy/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/xored_low_entropy_staged_meterpreter.hpp
        src/shellcodes/xored_low_entropy_unstaged_meterpreter.hpp
        src/shellcodes/xored_low_entropy_calc.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # rename the currect SHELLCODE_NAME to remove the "xored_" prefix
    string(REGEX REPLACE "xored_(.*)" "\\1" SHELLCODE_NAME ${SHELLCODE_NAME})

    # Create an executable for the current shellcode
    # The executable must have the name of the shellcode but preceding it with "xored_"
    add_executable(xored_low_entropy${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "xored_" and ending with "_debug"
    add_executable(xored_low_entropy${SHELLCODE_NAME}_debug ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(xored_low_entropy${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(xored_low_entropy${SHELLCODE_NAME}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(xored_low_entropy${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(xored_low_entropy${SHELLCODE_NAME}_debug PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()
# now let's do the same for the executable src/technique_3_sandbox_escape/sheellcode_dropper.cpp
# Set the source file
set(SOURCE_FILE src/technique_3_sandbox_escape/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/calc.hpp
        src/shellcodes/unstaged_meterpreter_reverse_shell.hpp
        src/shellcodes/staged_meterpreter_reverse_shell.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # Create an executable for the current shellcode
    add_executable(sandbox_escape_${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "sandbox_escape_" and ending with "_debug"
    add_executable(sandbox_escape_${SHELLCODE_NAME}_debug ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(sandbox_escape_${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(sandbox_escape_${SHELLCODE_NAME}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(sandbox_escape_${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(sandbox_escape_${SHELLCODE_NAME}_debug PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()


# now let's do the same for the executable src/technique_4_clear_import_address_table/main.cpp
# Set the source file
set(SOURCE_FILE src/technique_4_clear_import_address_table/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/calc.hpp
        src/shellcodes/unstaged_meterpreter_reverse_shell.hpp
        src/shellcodes/staged_meterpreter_reverse_shell.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # Create an executable for the current shellcode
    # The name of the executable should be "clean_IAT_" followed by the shellcode name
    add_executable(clean_IAT_${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "clean_IAT_" and ending with "_debug"
    add_executable(clean_IAT_${SHELLCODE_NAME}_debug ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(clean_IAT_${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(clean_IAT_${SHELLCODE_NAME}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(clean_IAT_${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(clean_IAT_${SHELLCODE_NAME}_debug PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()


# now let's do the same for the executable src/technique_5_bypassing_etw/main.cpp
# Set the source file
set(SOURCE_FILE src/technique_5_bypassing_etw/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/calc.hpp
        src/shellcodes/unstaged_meterpreter_reverse_shell.hpp
        src/shellcodes/staged_meterpreter_reverse_shell.hpp
        )

# Loop over the list of shellcodes
foreach(SHELLCODE ${SHELLCODES})
    # Extract the shellcode name from the file path
    get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
    # old config used regex, but somehow it didn't work
    # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

    # Create an executable for the current shellcode
    # The name of the executable should be "etw_bypass_" followed by the shellcode name
    add_executable(etw_bypass_${SHELLCODE_NAME} ${SOURCE_FILE})
    # Create another executable called the same but starting with "etw_bypass_" and ending with "_debug"
    add_executable(etw_bypass_${SHELLCODE_NAME}_debug ${SOURCE_FILE})

    # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
    target_compile_definitions(etw_bypass_${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0)
    # Set the debug preprocessor definitions as above, but with debug=1
    target_compile_definitions(etw_bypass_${SHELLCODE_NAME}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1)

    # Set the static linking flags for both executables
    set_target_properties(etw_bypass_${SHELLCODE_NAME} PROPERTIES LINK_FLAGS "-static")
    set_target_properties(etw_bypass_${SHELLCODE_NAME}_debug PROPERTIES LINK_FLAGS "-static")

    # old line where the relative path was set by hand
    # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
endforeach()


# now let's do the same for the executable src/all_techniques_combined/sheellcode_dropper.cpp
# Set the source file
set(SOURCE_FILE src/all_techniques_combined/main.cpp)

# Set the list of shellcodes
set(SHELLCODES
        src/shellcodes/xored_low_entropy_calc.hpp
        src/shellcodes/xored_low_entropy_staged_meterpreter.hpp
        src/shellcodes/xored_low_entropy_unstaged_meterpreter.hpp
        )

# Set a list containing the numbers 100000, 400000 and 500000
set(DELAY_LIST 100000 200000 300000 400000 500000)

# Loop over the numbers in DELAY_LIST
foreach(DELAY ${DELAY_LIST})

    # Loop over the list of shellcodes
    foreach(SHELLCODE ${SHELLCODES})
        # Extract the shellcode name from the file path
        get_filename_component(SHELLCODE_NAME ${SHELLCODE} NAME_WE)
        # old config used regex, but somehow it didn't work
        # string(REGEX REPLACE ".*/([^/]*).hpp" "\\1" SHELLCODE_NAME ${SHELLCODE})

        # rename the currect SHELLCODE_NAME to remove the "xored_" prefix
        string(REGEX REPLACE "xored_(.*)" "\\1" SHELLCODE_NAME ${SHELLCODE_NAME})

        # Create an executable for the current shellcode
        # The name of the executable should be "all_techniques_" followed by the shellcode name and ending with "_delay_" followed by the current delay
        add_executable(all_techniques_${SHELLCODE_NAME}_delay_${DELAY} ${SOURCE_FILE})
        # Create another executable called the same but starting with "all_techniques_" and ending with "_delay_" followed by the current delay and then "_debug"
        add_executable(all_techniques_${SHELLCODE_NAME}_delay_${DELAY}_debug ${SOURCE_FILE})

        # Add the current shellcode as a preprocessor definition for the executable, called SHELLCODE_PATH, but add the absolute path to the file
        # Also add a preprocessor definition called DELAY with the current delay
        target_compile_definitions(all_techniques_${SHELLCODE_NAME}_delay_${DELAY} PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=0 PRIVATE DELAY=${DELAY})
        # Set the debug preprocessor definitions as above, but with debug=1
        target_compile_definitions(all_techniques_${SHELLCODE_NAME}_delay_${DELAY}_debug PRIVATE SHELLCODE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/${SHELLCODE}" PRIVATE DEBUG=1 PRIVATE DELAY=${DELAY})

        # Set the static linking flags for both executables
        set_target_properties(all_techniques_${SHELLCODE_NAME}_delay_${DELAY} PROPERTIES LINK_FLAGS "-static")
        set_target_properties(all_techniques_${SHELLCODE_NAME}_delay_${DELAY}_debug PROPERTIES LINK_FLAGS "-static")

        # old line where the relative path was set by hand
        # target_compile_definitions(${SHELLCODE_NAME} PRIVATE SHELLCODE_PATH="../../${SHELLCODE}")
    endforeach()

endforeach()
