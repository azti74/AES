#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tests.h"
#include "aes.h"
#include "conversion.h"




void verifier_test(char *name, char *test, char *verif) {
    if (strcmp(test, verif) == 0) {
        printf("\n\033[0;32m");
        printf("%s : ok\n", name);
        printf("ATTENDU : %s\n", verif);
        printf("RESULT  : %s\n", test);
        printf("\033[0m");
    } else {
        printf("\n\033[0;31m");
        printf("%s : ko\n", name);
        printf("ATTENDU : %s\n", verif);
        printf("RESULT  : %s\n", test);
        printf("\033[0m");
        

    }
}


void test_mixColumn() {


    /*              TEST 1            */
    /*      Attendu :                 */
    char attendu1[] = "046681e5e0cb199a48f8d37a2806264c";

    /*      Entrée du test :          */
    byte test1[16] = {0xd4, 0xbf, 0x5d, 0x30, 0xe0, 0xb4, 0x52, 0xae, 0xb8, 0x41, 0x11, 0xf1, 0x1e, 0x27, 0x98, 0xe5};
    
    /*      Commande a tester :       */
    mixColumn(test1);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("mixcolumn test1", result1, attendu1);

}

void test_invMixColumn() {


    /*              TEST 1            */
    /*      Attendu :                 */
    char attendu1[] = "4773b91ff72f354361cb018ea1e6cf2c";

    /*      Entrée du test :          */
    byte test1[16] = {0xbd, 0x6e, 0x7c, 0x3d, 0xf2, 0xb5, 0x77, 0x9e, 0x0b, 0x61, 0x21, 0x6e, 0x8b, 0x10, 0xb6, 0x89};
    
    /*      Commande a tester :       */
    invMixColumn(test1);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("invMixcolumn test1", result1, attendu1);

}


void test_subBytes() {

    /*==============TEST 1============*/
    /*      Attendu :                 */
    char attendu1[] = "d42711aee0bf98f1b8b45de51e415230";

    /*      Entrée du test :          */
    byte test1[16] = {0x19, 0x3d, 0xe3, 0xbe, 0xa0, 0xf4, 0xe2, 0x2b, 0x9a, 0xc6, 0x8d, 0x2a, 0xe9, 0xf8, 0x48, 0x08};

    /*      Commande a tester :       */
    subBytes(test1);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("subBytes test1", result1, attendu1);
}

void test_invSubBytes() {

    /*==============TEST 1============*/
    /*      Attendu :                 */
    char attendu1[] = "bdb52189f261b63d0b107c9e8b6e776e";

    /*      Entrée du test :          */
    byte test1[16] = {0x7a, 0xd5, 0xfd, 0xa7, 0x89, 0xef, 0x4e, 0x27, 0x2b, 0xca, 0x10, 0x0b, 0x3d, 0x9f, 0xf5, 0x9f};

    /*      Commande a tester :       */
    invSubBytes(test1);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("invSubBytes test1", result1, attendu1);
}

void test_addRoundKey() {

    /*==============TEST 1============*/
    /*      Attendu :                 */
    char attendu1[] = "a49c7ff2689f352b6b5bea43026a5049";

    /*      Entrée du test :          */
    byte test1[16] = {0x04, 0x66, 0x81, 0xe5, 0xe0, 0xcb, 0x19, 0x9a, 0x48, 0xf8, 0xd3, 0x7a, 0x28, 0x06, 0x26, 0x4c};
    byte test1_key[16] = {0xa0, 0xfa, 0xfe, 0x17, 0x88, 0x54, 0x2c, 0xb1, 0x23, 0xa3, 0x39, 0x39, 0x2a, 0x6c, 0x76, 0x05};

    /*      Commande a tester :       */
    addRoundKey(test1, test1_key);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("addRoundKey test1", result1, attendu1);
}

void test_shiftRows() {

    /*==============TEST 1============*/
    /*      Attendu :                 */
    char attendu1[] = "d4bf5d30e0b452aeb84111f11e2798e5";

    /*      Entrée du test :          */
    byte test1[16] = {0xd4, 0x27, 0x11, 0xae, 0xe0, 0xbf, 0x98, 0xf1, 0xb8, 0xb4, 0x5d, 0xe5, 0x1e, 0x41, 0x52, 0x30};

    /*      Commande a tester :       */
    shiftRows(test1);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("shiftRows test1", result1, attendu1);
}

void test_invShiftRows() {

    /*==============TEST 1============*/
    /*      Attendu :                 */
    char attendu1[] = "3e175076b61c04678dfc2295f6a8bfc0";

    /*      Entrée du test :          */
    char test1bis[] = "3e1c22c0b6fcbf768da85067f6170495";
    byte test1[16];// = {0x3e, 0x1c, 0x22, 0xc0, 0xb6, 0xfc, 0xbf, 0x76, 0x8d, 0xa8, 0x50, 0x67, 0xf6, 0x17, 0x04, 0x95};
    strToState(test1bis, test1);

    /*      Commande a tester :       */
    invShiftRows(test1);

    /*     Conversion(NE PAS MODIFIER)*/
    char result1[33] = "";
    stateToStr(test1, result1);
    /*      Véfification du test      */
    verifier_test("invShiftRows test1", result1, attendu1);


    /*==============TEST 2============*/
    /*      Attendu :                 */
    char attendu2[] = "5411f4b56bd9700e96a0902fa1bb9aa1";

    /*      Entrée du test :          */
    char test2bis[] = "54d990a16ba09ab596bbf40ea111702f";
    byte test2[16];
    strToState(test2bis, test2);

    /*      Commande a tester :       */
    invShiftRows(test2);

    /*     Conversion(NE PAS MODIFIER)*/
    char result2[33] = "";
    stateToStr(test2, result2);
    /*      Véfification du test      */
    verifier_test("invShiftRows test2", result2, attendu2);
}

void test_keyExpansion(){
    // AES 128
    char key[] = "2b7e151628aed2a6abf7158809cf4f3c";
    byte input[16];
    strToWords(key, input, 32);
    byte* result = keyExpansion(input, 4, 10);
    char result2[4*44*2+1] = "";
    wordsToStr(result, result2, 4*44);
    verifier_test("Test AES 128 : keyExpansion", result2, "2b7e151628aed2a6abf7158809cf4f3ca0fafe1788542cb123a339392a6c7605f2c295f27a96b9435935807a7359f67f3d80477d4716fe3e1e237e446d7a883bef44a541a8525b7fb671253bdb0bad00d4d1c6f87c839d87caf2b8bc11f915bc6d88a37a110b3efddbf98641ca0093fd4e54f70e5f5fc9f384a64fb24ea6dc4fead27321b58dbad2312bf5607f8d292fac7766f319fadc2128d12941575c006ed014f9a8c9ee2589e13f0cc8b6630ca6");
    free(result);


    // AES 192
    char keyb[] = "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b";
    byte inputb[24];
    strToWords(keyb, inputb, 48);
    byte* resultb = keyExpansion(inputb, 6, 12);
    char result2b[4*52*2+1] = "";
    wordsToStr(resultb, result2b, 4*52);
    verifier_test("Test AES 192 : keyExpansion", result2b, "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7bfe0c91f72402f5a5ec12068e6c827f6b0e7a95b95c56fec24db7b4bd69b5411885a74796e92538fde75fad44bb095386485af05721efb14fa448f6d94d6dce24aa326360113b30e6a25e7ed583b1cf9a27f939436a94f767c0a69407d19da4e1ec1786eb6fa64971485f703222cb8755e26d135233f0b7b340beeb282f18a2596747d26b458c553ea7e1466c9411f1df821f750aad07d753ca4005388fcc5006282d166abc3ce7b5e98ba06f448c773c8ecc720401002202");
    free(resultb);


    // AES 256
    char keyc[] = "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4";
    byte inputc[32];
    strToWords(keyc, inputc, 64);
    byte* resultc = keyExpansion(inputc, 8, 14);
    char result2c[4*62*2+1] = "";
    wordsToStr(resultc, result2c, 4*60);
    verifier_test("Test AES 256 : keyExpansion", result2c, "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff49ba354118e6925afa51a8b5f2067fcdea8b09c1a93d194cdbe49846eb75d5b9ad59aecb85bf3c917fee94248de8ebe96b5a9328a2678a647983122292f6c79b3812c81addadf48ba24360af2fab8b46498c5bfc9bebd198e268c3ba709e0421468007bacb2df331696e939e46c518d80c814e20476a9fb8a5025c02d59c58239de1369676ccc5a71fa2563959674ee155886ca5d2e2f31d77e0af1fa27cf73c3749c47ab18501ddae2757e4f7401905acafaaae3e4d59b349adf6acebd10190dfe4890d1e6188d0b046df344706c631e");
    free(resultc);
    
    
}
void test_cipher(){
    // AES 128
    char key[] = "2b7e151628aed2a6abf7158809cf4f3c";
    byte key_input[16];
    strToWords(key, key_input, 32);

    char text[32] = "3243f6a8885a308d313198a2e0370734";
    byte input[16];
    strToState(text, input);

    byte *state = chiffrer(key_input, input, 4);

    char output[33] = "";
    stateToStr(state, output);

    verifier_test("Cipher AES 128", output, "3925841d02dc09fbdc118597196a0b32"); 
    free(state);



    //AES 192
    char keyb[] = "000102030405060708090a0b0c0d0e0f1011121314151617";
    byte key_inputb[24];
    strToWords(keyb, key_inputb, 48);

    char textb[32] = "00112233445566778899aabbccddeeff";
    byte inputb[16];
    strToState(textb, inputb);

    byte *stateb = chiffrer(key_inputb, inputb, 6);

    char outputb[33] = "";
    stateToStr(stateb, outputb);

    verifier_test("Cipher AES 192", outputb, "dda97ca4864cdfe06eaf70a0ec0d7191"); 
    free(stateb);



    // AES 256
    char keyc[] = "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f";
    byte key_inputc[32];
    strToWords(keyc, key_inputc, 64);

    char textc[32] = "00112233445566778899aabbccddeeff";
    byte inputc[16];
    strToState(textc, inputc);

    byte *statec = chiffrer(key_inputc, inputc, 8);

    char outputc[33] = "";
    stateToStr(statec, outputc);

    verifier_test("Cipher AES 256", outputc, "8ea2b7ca516745bfeafc49904b496089"); 
    free(statec);
}

void test_invCipher(){
    // AES 128
    char key[] = "2b7e151628aed2a6abf7158809cf4f3c";
    byte key_input[16];
    strToWords(key, key_input, 32);

    char text[32] = "3925841d02dc09fbdc118597196a0b32";
    byte input[16];
    strToState(text, input);

    byte *state = dechiffrer(key_input, input, 4);

    char output[33] = "";
    stateToStr(state, output);

    verifier_test("invCipher AES 128", output, "3243f6a8885a308d313198a2e0370734"); 
    free(state);



    //AES 192
    char keyb[] = "000102030405060708090a0b0c0d0e0f1011121314151617";
    byte key_inputb[24];
    strToWords(keyb, key_inputb, 48);

    char textb[32] = "dda97ca4864cdfe06eaf70a0ec0d7191";
    byte inputb[16];
    strToState(textb, inputb);

    byte *stateb = dechiffrer(key_inputb, inputb, 6);

    char outputb[33] = "";
    stateToStr(stateb, outputb);

    verifier_test("invCipher AES 192", outputb, "00112233445566778899aabbccddeeff"); 
    free(stateb);



    // AES 256
    char keyc[] = "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f";
    byte key_inputc[32];
    strToWords(keyc, key_inputc, 64);

    char textc[32] = "8ea2b7ca516745bfeafc49904b496089";
    byte inputc[16];
    strToState(textc, inputc);

    byte *statec = dechiffrer(key_inputc, inputc, 8);

    char outputc[33] = "";
    stateToStr(statec, outputc);

    verifier_test("invCipher AES 256", outputc, "00112233445566778899aabbccddeeff"); 
    free(statec);
}

void all_tests() {
    test_mixColumn();
    test_invMixColumn();
    test_subBytes();
    test_invSubBytes();
    test_addRoundKey();
    test_shiftRows();
    test_invShiftRows();
    test_keyExpansion();
    test_cipher();
    test_invCipher();
}



