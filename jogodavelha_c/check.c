char checa_dp(char mat[3][3]){
    for(int i = 1; i < 3; i++){
        if((mat[i][i] == ' ') || (mat[i][i] != mat[i-1][i-1])){
            return 0;
        }
    }
    return 1;
}

char checa_ds(char mat[3][3]){
    for(int i = 0; i < 2; i++){
        for(int j = 2; j > 0; j--){
            if(i+j == 2){
                if((mat[i][j] == ' ') || (mat[i][j] != mat[i+1][j-1])){
                    return 0;
                }
            }
        }
    }
    return 1;
}

char checa_lin(char mat[3][3]){
    int i = 0, j = 1;
    while((i < 3) && (j < 3)){
        if(mat[i][j] == ' '){
            i++;
            j = 1;
        } else if(mat[i][j] != mat[i][j-1]){
            i++;
            j = 1;
        } else{
            j++;
        }
    }
    if (i >= 3){
        return 0;
    }
    return 1;
}

char checa_col(char mat[3][3]){
    int i = 1, j = 0;
    while((i < 3) && (j < 3)){
        if(mat[i][j] == ' '){
            j++;
            i = 1;
        } else if(mat[i][j] != mat[i-1][j]){
            j++;
            i = 1;
        } else{
            i++;
        }
    }
    if (j >= 3){
        return 0;
    }
    return 1;
}

char checa_velha(char mat[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(mat[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}