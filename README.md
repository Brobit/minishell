# minishell

## things to do

## mandatory things

    - [ ] display a prompt when waiting for a new command
    - [ ] have a working history
    - [ ] search and launch the right executable (base on the 
        PATH variable or using relative or an absolute path)
    - [ ] use only one global variable to indicate a received signal
    - [ ] not interpret unclosed quotes or special characters 
        which are not required by the subject such as \ or ;
    - [ ] handle '' (single quotes) which should prevent the 
        shell from interpreting the metacharacter in the quoted sequence
    - [ ] handle "" (double quote) which should prevent the
        shell grom interpreting the metacharacter in the quoted sequence
        exept for $
    - [ ] implementation redirection :
        - [ ] < should redirect input
        - [ ] > should redirect output
        - [ ] << should be given a delimiter, then read the input
            until a line containing the delimiter is seen. 
            However, it doesn't have to update the history.
            Put the command in wait mode until encounter the delimiter,
            then, execute the command
        - [ ] >> should redirect output in append mode
    - [ ] implement pipes ( | ) , the output of each command in the
        the pipeline is connected to the input of the next command
        via a pipe
    - [ ] handle environment variable ($ followed by a sequence of character)
        which should expand to heir values
    - [ ] handle $? which should expandto the exit status of the most
        recently executed foregound pipeline
    - [ ] handle crtl-C , ctrl-D , and ctrl-\ which shold behave like in bash
    - [ ] in interactive mode :
        - [ ] ctrl-C displays a new prompt on a new line
        - [ ] ctrl-D exit the shell
        - [ ] ctrl-\ does nothing

## builtins to implement :

    - [ ] echo with option -n
    - [ ] cd with only a relative or absolute path
    - [ ] pwd with no options
    - [ ] export with no options
    - [ ] unset with no options
    - [ ] env with no options or arguments
    - [ ] exit with no options
