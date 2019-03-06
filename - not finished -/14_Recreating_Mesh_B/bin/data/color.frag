#ifdef GL_ES
precision mediump float;
#endif

#define PROCESSING_COLOR_SHADER

uniform vec2 u_resolution;
uniform vec3 u_mouse;
uniform float u_time;
uniform float m_curves;
uniform float m_redInit;
uniform float m_redEnd;
uniform float m_greenInit;
uniform float m_greenEnd;
uniform float m_blueInit;
uniform float m_blueEnd;

vec2 random2( vec2 p ) {
    return fract(sin(vec2(dot(p,vec2(127.1,311.7)), dot(p,vec2(269.5,183.3))))*43758.5453);
}

void main() {
    vec2 coord = m_curves * gl_FragCoord.xy / u_resolution;

    for(int n = 1; n < 3; n++){
        float i = float(n);
        float movA = 0.4 / i * sin(i * coord.y + u_time + 0.3 * i) + 50.0;
        float movB = 0.7 / i * sin(coord.x + u_time + 0.3 * i) + 6.0;
        coord += vec2(movA, movB);
    }

    float r = m_redInit * sin(coord.y) + m_redEnd;
    float g = m_greenInit * cos(coord.x) + m_greenEnd;
    float b = m_blueInit * cos(coord.x) + m_blueEnd;

    vec3 color = vec3(r, g, b);

    gl_FragColor = vec4(color, 1.0);


/*
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;
    vec3 color = vec3(.0);

    // Scale
    st *= 5.;

    // Tile the space
    vec2 i_st = floor(st);
    vec2 f_st = fract(st);

    float m_dist = 1.;  // minimun distance
    for (int j= -1; j <= 1; j++ ) {
        for (int i= -1; i <= 1; i++ ) {
            vec2 neighbor = vec2(float(i),float(j));
            vec2 offset = random2(i_st + neighbor);
            offset = 0.5 + 0.5*sin(u_time + 6.2831*offset);
            vec2 pos = neighbor + offset - f_st;
            float dist = length(pos);
            m_dist = min(m_dist, m_dist*dist);
        }
    }

    // Draw cells
    color += step(0.060, m_dist);
    gl_FragColor = vec4(color, 1.0);
    */
}