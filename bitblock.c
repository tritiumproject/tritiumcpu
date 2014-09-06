#include "cpuminer-config.h"
#include "miner.h"

#include <string.h>
#include <stdint.h>

#include "sph_blake.h"
#include "sph_md2.h"
#include "sph_md4.h"
#include "sph_shabal.h"
#include "sph_bmw.h"
#include "sph_groestl.h"
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_skein.h"
#include "sph_luffa.h"
#include "sph_cubehash.h"
#include "sph_shavite.h"
#include "sph_simd.h"
#include "sph_echo.h"
#include "sph_hamsi.h"
#include "sph_fugue.h"
#include "sph_shabal.h"
#include "sph_whirlpool.h"
#include "sph_haval.h"
#include "sph_md5.h"
#include "sph_panama.h"
#include "sph_radiogatun.h"
#include "sph_ripemd.h"
#include "sph_sha0.h"
#include "sph_sha1.h"
#include "sph_sha22.h"
#include "sph_sha3.h"
#include "sph_tiger.h"







inline void bitblockhash(void *output, const void *input)
{
    unsigned char hash[550];

    memset(hash, 0, 550);
  
	//sph_haval128_3_context     ctx_haval128_3;
	sph_haval128_4_context     ctx_haval128_4;
	sph_haval128_5_context     ctx_haval128_5;
	sph_haval160_3_context     ctx_haval160_3;
	//sph_haval160_4_context     ctx_haval160_4;
	sph_haval160_5_context     ctx_haval160_5;
	sph_haval192_3_context     ctx_haval192_3;
	sph_haval192_4_context     ctx_haval192_4;
	sph_haval192_5_context     ctx_haval192_5;
	//sph_haval224_3_context     ctx_hava224_3;
	sph_haval224_4_context     ctx_haval224_4;
	sph_haval224_5_context     ctx_haval224_5;
	sph_haval256_3_context     ctx_haval256_3;
	sph_haval256_4_context     ctx_haval256_4;
	sph_haval256_5_context     ctx_haval256_5;

	sph_keccak256_context    ctx_keccak256;

	sph_blake512_context     ctx_blake;
	sph_bmw512_context       ctx_bmw;
	sph_groestl512_context   ctx_groestl;
	sph_jh512_context        ctx_jh;
	sph_keccak512_context    ctx_keccak;
	sph_skein512_context     ctx_skein;
	sph_luffa512_context     ctx_luffa;
	sph_cubehash512_context  ctx_cubehash;
	sph_shavite512_context   ctx_shavite;
	sph_simd512_context      ctx_simd;
	sph_echo512_context      ctx_echo;
	sph_hamsi512_context      ctx_hamsi;
	sph_fugue512_context      ctx_fugue;
	sph_shabal512_context     ctx_shabal;

	sph_whirlpool_context     ctx_whirlpool;
	sph_whirlpool0_context     ctx_whirlpool0;
	sph_whirlpool1_context     ctx_whirlpool1;

	sph_tiger_context     ctx_tiger;
	sph_tiger2_context     ctx_tiger2;

	sph_md2_context     ctx_md2;
	sph_md4_context     ctx_md4;
	sph_md5_context     ctx_md5;

	sph_panama_context     ctx_panama;

	sph_radiogatun32_context     ctx_radiogatun32;
	sph_radiogatun64_context     ctx_radiogatun64;

	sph_ripemd_context     ctx_ripemd;
	sph_ripemd128_context     ctx_ripemd128;
	sph_ripemd160_context     ctx_ripemd160;

	sph_sha0_context     ctx_sha0;
	sph_sha1_context     ctx_sha1;
	sph_sha224_context     ctx_sha224;
	sph_sha256_context     ctx_sha256;
	sph_sha384_context     ctx_sha384;
	sph_sha512_context     ctx_sha512;

    

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, input, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);
	//set2-50
	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);
	//set 50
	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

	sph_radiogatun32_init(&ctx_radiogatun32); // No 19
	sph_radiogatun32(&ctx_radiogatun32, hash + 64, 80);
	sph_radiogatun32_close(&ctx_radiogatun32, hash);

	sph_sha224_init(&ctx_sha224); //no 29
	sph_sha224(&ctx_sha224, hash, 64);
	sph_sha224_close(&ctx_sha224, hash + 64);

	sph_bmw512_init(&ctx_bmw); //39
	sph_bmw512(&ctx_bmw, hash + 64, 64);
	sph_bmw512_close(&ctx_bmw, hash);

	sph_luffa512_init(&ctx_luffa);//47
	sph_luffa512(&ctx_luffa, hash, 64);
	sph_luffa512_close(&ctx_luffa, hash + 64);

	sph_haval256_4_init(&ctx_haval256_4); //13
	sph_haval256_4(&ctx_haval256_4, hash + 64, 64);
	sph_haval256_4_close(&ctx_haval256_4, hash);

	sph_panama_init(&ctx_panama); //9
	sph_panama(&ctx_panama, hash, 64);
	sph_panama_close(&ctx_panama, hash + 64);

	sph_md2_init(&ctx_md2); //15
	sph_md2(&ctx_md2, hash + 64, 64);
	sph_md2_close(&ctx_md2, hash);

	sph_haval224_4_init(&ctx_haval224_4);//10
	sph_haval224_4(&ctx_haval224_4, hash, 64);
	sph_haval224_4_close(&ctx_haval224_4, hash + 64);

	sph_blake512_init(&ctx_blake);//38
	sph_blake512(&ctx_blake, hash + 64, 64);
	sph_blake512_close(&ctx_blake, hash);

	sph_haval128_4_init(&ctx_haval128_4);//1
	sph_haval128_4(&ctx_haval128_4, hash, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash + 64);

	sph_sha1_init(&ctx_sha1);//28
	sph_sha1(&ctx_sha1, hash + 64, 64);
	sph_sha1_close(&ctx_sha1, hash);

	sph_cubehash512_init(&ctx_cubehash);//40
	sph_cubehash512(&ctx_cubehash, hash, 64);
	sph_cubehash512_close(&ctx_cubehash, hash + 64);

	sph_fugue512_init(&ctx_fugue);//18
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_haval192_3_init(&ctx_haval192_3);//6
	sph_haval192_3(&ctx_haval192_3, hash, 64);
	sph_haval192_3_close(&ctx_haval192_3, hash + 64);

	sph_tiger2_init(&ctx_tiger2);//34 //set1
	sph_tiger2(&ctx_tiger2, hash + 64, 64);
	sph_tiger2_close(&ctx_tiger2, hash);

	sph_skein512_init(&ctx_skein); // No 46
	sph_skein512(&ctx_skein, hash, 64);
	sph_skein512_close(&ctx_skein, hash + 64);

	sph_shabal512_init(&ctx_shabal); //no 48
	sph_shabal512(&ctx_shabal, hash + 64, 64);
	sph_shabal512_close(&ctx_shabal, hash);

	sph_bmw512_init(&ctx_bmw); //20
	sph_bmw512(&ctx_bmw, hash, 64);
	sph_bmw512_close(&ctx_bmw, hash + 64);

	sph_hamsi512_init(&ctx_hamsi);//44
	sph_hamsi512(&ctx_hamsi, hash + 64, 64);
	sph_hamsi512_close(&ctx_hamsi, hash);

	sph_haval160_5_init(&ctx_haval160_5); //5
	sph_haval160_5(&ctx_haval160_5, hash, 64);
	sph_haval160_5_close(&ctx_haval160_5, hash + 64);

	sph_ripemd_init(&ctx_ripemd); //21
	sph_ripemd(&ctx_ripemd, hash + 64, 64);
	sph_ripemd_close(&ctx_ripemd, hash);

	sph_ripemd160_init(&ctx_ripemd160); //23
	sph_ripemd160(&ctx_ripemd160, hash, 64);
	sph_ripemd160_close(&ctx_ripemd160, hash + 64);

	sph_whirlpool0_init(&ctx_whirlpool0);//36
	sph_whirlpool0(&ctx_whirlpool0, hash + 64, 64);
	sph_whirlpool0_close(&ctx_whirlpool0, hash);

	sph_tiger_init(&ctx_tiger);//33
	sph_tiger(&ctx_tiger, hash, 64);
	sph_tiger_close(&ctx_tiger, hash + 64);

	sph_groestl512_init(&ctx_groestl);//43
	sph_groestl512(&ctx_groestl, hash + 64, 64);
	sph_groestl512_close(&ctx_groestl, hash);

	sph_whirlpool1_init(&ctx_whirlpool1);//37
	sph_whirlpool1(&ctx_whirlpool1, hash, 64);
	sph_whirlpool1_close(&ctx_whirlpool1, hash + 64);

	sph_haval256_3_init(&ctx_haval256_3);//12
	sph_haval256_3(&ctx_haval256_3, hash + 64, 64);
	sph_haval256_3_close(&ctx_haval256_3, hash);

	sph_echo512_init(&ctx_echo);//4
	sph_echo512(&ctx_echo, hash, 64);
	sph_echo512_close(&ctx_echo, hash + 64);

	sph_haval256_5_init(&ctx_haval256_5);//14
	sph_haval256_5(&ctx_haval256_5, hash + 64, 64);
	sph_haval256_5_close(&ctx_haval256_5, hash);

	sph_md4_init(&ctx_md4);//16
	sph_md4(&ctx_md4, hash, 64);
	sph_md4_close(&ctx_md4, hash + 64);

	sph_shavite512_init(&ctx_shavite);//49 //set2
	sph_shavite512(&ctx_shavite, hash + 64, 64);
	sph_shavite512_close(&ctx_shavite, hash);

	sph_haval160_3_init(&ctx_haval160_3); // No 3
	sph_haval160_3(&ctx_haval160_3, hash, 64);
	sph_haval160_3_close(&ctx_haval160_3, hash + 64);

	sph_keccak512_init(&ctx_keccak); //no 24
	sph_keccak512(&ctx_keccak, hash + 64, 64);
	sph_keccak512_close(&ctx_keccak, hash);

	sph_sha512_init(&ctx_sha512); //32
	sph_sha512(&ctx_sha512, hash, 64);
	sph_sha512_close(&ctx_sha512, hash + 64);

	sph_fugue512_init(&ctx_fugue);//42
	sph_fugue512(&ctx_fugue, hash + 64, 64);
	sph_fugue512_close(&ctx_fugue, hash);

	sph_keccak256_init(&ctx_keccak256); //25
	sph_keccak256(&ctx_keccak256, hash, 64);
	sph_keccak256_close(&ctx_keccak256, hash + 64);

	sph_ripemd128_init(&ctx_ripemd128); //22
	sph_ripemd128(&ctx_ripemd128, hash + 64, 64);
	sph_ripemd128_close(&ctx_ripemd128, hash);

	sph_simd512_init(&ctx_simd); //26
	sph_simd512(&ctx_simd, hash, 64);
	sph_simd512_close(&ctx_simd, hash + 64);

	sph_sha0_init(&ctx_sha0);//27
	sph_sha0(&ctx_sha0, hash + 64, 64);
	sph_sha0_close(&ctx_sha0, hash);

	sph_haval192_4_init(&ctx_haval192_4);//7
	sph_haval192_4(&ctx_haval192_4, hash, 64);
	sph_haval192_4_close(&ctx_haval192_4, hash + 64);

	sph_sha384_init(&ctx_sha384);//31
	sph_sha384(&ctx_sha384, hash + 64, 64);
	sph_sha384_close(&ctx_sha384, hash);

	sph_haval128_5_init(&ctx_haval128_5);//2
	sph_haval128_5(&ctx_haval128_5, hash, 64);
	sph_haval128_5_close(&ctx_haval128_5, hash + 64);

	sph_haval224_5_init(&ctx_haval224_5);//11
	sph_haval224_5(&ctx_haval224_5, hash + 64, 64);
	sph_haval224_5_close(&ctx_haval224_5, hash);

	sph_jh512_init(&ctx_jh);//45
	sph_jh512(&ctx_jh, hash, 64);
	sph_jh512_close(&ctx_jh, hash + 64);

	sph_sha256_init(&ctx_sha256);//30
	sph_sha256(&ctx_sha256, hash + 64, 64);
	sph_sha256_close(&ctx_sha256, hash);

	sph_haval192_5_init(&ctx_haval192_5);//8
	sph_haval192_5(&ctx_haval192_5, hash, 64);
	sph_haval192_5_close(&ctx_haval192_5, hash + 64);

	sph_md5_init(&ctx_md5);//17
	sph_md5(&ctx_md5, hash + 64, 64);
	sph_md5_close(&ctx_md5, hash);

	sph_whirlpool_init(&ctx_whirlpool);//35
	sph_whirlpool(&ctx_whirlpool, hash, 64);
	sph_whirlpool_close(&ctx_whirlpool, hash + 64);

	sph_haval128_4_init(&ctx_haval128_4);//35
	sph_haval128_4(&ctx_haval128_4, hash + 64, 64);
	sph_haval128_4_close(&ctx_haval128_4, hash);

	sph_radiogatun64_init(&ctx_radiogatun64);//20
	sph_radiogatun64(&ctx_radiogatun64, hash, 64);
	sph_radiogatun64_close(&ctx_radiogatun64, hash + 64);

    memcpy(output, hash, 32);
}

int scanhash_bitblock(int thr_id, uint32_t *pdata, const uint32_t *ptarget,
    uint32_t max_nonce, unsigned long *hashes_done)
{
    uint32_t n = pdata[19] - 1;
    const uint32_t first_nonce = pdata[19];
    const uint32_t Htarg = ptarget[7];

    uint32_t hash64[8] __attribute__((aligned(32)));
    uint32_t endiandata[32];

    //we need bigendian data...
    //lessons learned: do NOT endianchange directly in pdata, this will all proof-of-works be considered as stale from minerd.... 
    int kk=0;
    for (; kk < 32; kk++)
    {
	      be32enc(&endiandata[kk], ((uint32_t*)pdata)[kk]);
    };

    do {
	      pdata[19] = ++n;
	      be32enc(&endiandata[19], n); 
	      bitblockhash(hash64, &endiandata);
            if (((hash64[7]&0xFFFFFF00)==0) && 
			      fulltest(hash64, ptarget)) {
                *hashes_done = n - first_nonce + 1;
		      return true;
	      }
    } while (n < max_nonce && !work_restart[thr_id].restart);

    *hashes_done = n - first_nonce + 1;
    pdata[19] = n;
    return 0;
}
