.MODEL SMALL
.STACK 100H
.DATA
N DB 0

.CODE      
MOV AX, @DATA
MOV DS, AX

MAIN PROC
    MOV AH, 1
    INT 21H
    MOV N, AL
    SUB N, 30H
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
        
    MOV CX, 1
    MOV AX, 1
    MOV BX, 1
    
    FOR:
        CMP CL, N
        JG EXIT
        MOV BX, CX
        MUL BX
        INC CX
    JMP FOR
        
    EXIT:
        ADD AX, 30H
        MOV DL, AL
        MOV AH, 2
        INT 21H
        MOV AH, 4CH
        INT 21H
MAIN ENDP
END MAIN