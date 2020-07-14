use super::libuuas;

fn geotag_image_request(pbbuffer: &[u8]) -> i32 {
    let ans = 0; //unsafe { libuuas::geotagImageRequest(pbbuffer.as_ptr(), pbbuffer.len() as i32) };
    return ans;
}
