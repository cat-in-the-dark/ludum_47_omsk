// manual version of raylib default shader
// modified for scan line effect
#version 100

precision mediump float;

varying vec2 fragTexCoord;
varying vec4 fragColor;

const vec2 size = vec2(960.0, 544.0);   // render size
const float samples = 8.0;          // pixels per axis; higher = bigger glow, worse performance
const float quality = 8.0; 	        // lower = smaller glow, better quality

uniform sampler2D texture0;
uniform vec4 colDiffuse;

void main()
{
    vec4 finalColor = texture2D(texture0, fragTexCoord) * fragColor;

    float y = floor(fragTexCoord.y * size.y);
    if ( int(mod(y,4.0)) == 3 ) {
        finalColor /= 2.0;
    }

    // "borrowed" from bloom.fs in examples
    vec4 sum = vec4(0.0);
    vec2 sizeFactor = vec2(1.0)/size*quality;

    const int range = 2;            // should be = (samples - 1)/2;

    for (int x = -range; x <= range; x++)
    {
        for (int y = -range; y <= range; y++)
        {
            sum += texture2D(texture0, fragTexCoord + vec2(x, y)*sizeFactor);
        }
    }

    // Calculate final fragment color
    gl_FragColor = ((sum/(samples*samples)) + finalColor)*colDiffuse;
}
