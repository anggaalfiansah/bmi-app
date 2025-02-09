import { useState } from "react";
import axios from "axios";
import { Box, Button, Container, HStack, Icon, Input, Stack } from "@chakra-ui/react";
import { FcAbout, FcBusinessman, FcBusinesswoman } from "react-icons/fc";
import { DialogBackdrop, DialogBody, DialogCloseTrigger, DialogContent, DialogFooter, DialogHeader, DialogRoot, DialogTrigger } from "./components/ui/dialog";
import { RadioCardItem, RadioCardRoot } from "./components/ui/radio-card";
import { Field } from "./components/ui/field";
import { Blockquote } from "./components/ui/blockquote";
import { default as BG } from "./assets/bg.png";

type ViewType = "FORM" | "RESULT";
type GenderType = "L" | "P";
type BMIResult = {
  name: string;
  gender: string;
  height: number;
  weight: number;
  age: number;
  bmi_score: number;
  status: string;
  suggestion: string;
};

const BMISingle = () => {
  const [result, set_result] = useState<undefined | BMIResult>();
  const [view, set_view] = useState<ViewType>("FORM");
  const [name, set_name] = useState("");
  const [gender, set_gender] = useState<GenderType>("L");
  const [height, set_height] = useState("");
  const [weight, set_weight] = useState("");
  const [age, set_age] = useState("");

  const onSubmit = async () => {
    const data = {
      name,
      gender,
      height,
      weight,
      age,
    };
    const request = await axios.post(`${window.location.href.split(":")[0]}:${window.location.href.split(":")[1]}:5000/api/bmi`, data);
    if (request.data.status === "success") {
      set_result(request.data.data);
      set_view("RESULT");
    }
  };
  return (
    <Container fluid alignSelf={"center"} maxW={"md"} h={"100vh"} py={"2"}>
      <Stack
        pos={"relative"}
        w={"full"}
        h={"full"}
        justifyContent={"center"}
        alignItems={"center"}
        p={"5"}
        borderWidth={"2px"}
        borderRadius={"md"}
        bgImage={`url(${BG})`}
        bgSize={"cover"}
        bgPos={"left"}
      >
        {/* about ScaleUp */}
        <AboutScaleUp />
        {/* form */}
        <Stack
          hidden={view !== "FORM"}
          alignItems={"center"}
          w="full"
          h="95%"
          p="6"
          borderRadius="lg"
          bg="rgba(255, 255, 255, 0.2)"
          boxShadow="0 4px 10px rgba(0, 0, 0, 0.1)"
          backdropFilter="blur(10px)"
          border="1px solid rgba(255, 255, 255, 0.3)"
        >
          <LogoScaleUp />
          <RadioCardRoot value={gender} onValueChange={(e) => set_gender(e.value as GenderType)} colorPalette="orange" orientation="vertical" align="center" w="full" defaultValue="L">
            <HStack align={"stretch"} w="full">
              <RadioCardItem
                flex="1"
                label="Laki-laki"
                icon={
                  <Icon fontSize="5xl">
                    <FcBusinessman />
                  </Icon>
                }
                indicator={false}
                key="L"
                value="L"
              />
              <RadioCardItem
                flex="1"
                label="Perempuan"
                icon={
                  <Icon fontSize="5xl">
                    <FcBusinesswoman />
                  </Icon>
                }
                indicator={false}
                key="P"
                value="P"
              />
            </HStack>
          </RadioCardRoot>
          <Field label="Nama" required>
            <Input value={name} onChange={(e) => set_name(e.target.value)} variant="flushed" placeholder="Masukan nama anda" />
          </Field>
          <Field label="Tinggi (cm)" required>
            <Input type="number" value={height} onChange={(e) => set_height(e.target.value)} variant="flushed" placeholder="Masukan tinggi badan anda" />
          </Field>
          <Field label="Berat (kg)" required>
            <Input type="number" value={weight} onChange={(e) => set_weight(e.target.value)} variant="flushed" placeholder="Masukan berat badan anda" />
          </Field>
          <Field label="Usia" required>
            <Input type="number" value={age} onChange={(e) => set_age(e.target.value)} variant="flushed" placeholder="Masukan usia anda" />
          </Field>
          <Button
            onClick={onSubmit}
            w="full"
            bg="linear-gradient(135deg, #ff9a3c, #ff6f61)"
            color="white"
            fontWeight="bold"
            fontSize="lg"
            borderRadius="full"
            shadow="md"
            _hover={{
              transform: "scale(1.05)",
              transition: "all 0.2s ease-in-out",
            }}
            _active={{
              transform: "scale(0.98)",
            }}
            my="5"
          >
            Hitung BMI
          </Button>
        </Stack>
        {/* result */}
        <Stack
          hidden={view !== "RESULT"}
          alignItems={"center"}
          w="full"
          h="95%"
          p="6"
          borderRadius="lg"
          bg="rgba(255, 255, 255, 0.2)"
          boxShadow="0 4px 10px rgba(0, 0, 0, 0.1)"
          backdropFilter="blur(10px)"
          border="1px solid rgba(255, 255, 255, 0.3)"
        >
          <LogoScaleUp />
          <Stack spaceY={".5em"} alignItems={"center"}>
            <Box px="2em" bg="linear-gradient(135deg, #ff9a3c, #ff6f61)" w="fit-content" shadow={"md"} borderRadius="full">
              <Box color="#3d1a16" fontFamily="Lobster" fontSize="1.25em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                Hasil Perhitungan Anda
              </Box>
            </Box>
            <HStack w={"full"} borderRadius={"md"} borderWidth={"2px"}>
              {result?.gender === "L" ? (
                <Stack gap={0} alignItems={"center"} justifyContent={"center"} w={"37.5%"} borderRadius={"md"} borderRightWidth={"2px"}>
                  <Icon fontSize="5xl">
                    <FcBusinessman />
                  </Icon>
                  <Box>Laki-laki</Box>
                </Stack>
              ) : (
                <Stack gap={0} alignItems={"center"} justifyContent={"center"} w={"37.5%"} borderRadius={"md"} borderRightWidth={"2px"}>
                  <Icon fontSize="5xl">
                    <FcBusinesswoman />
                  </Icon>
                  <Box>Perempuan</Box>
                </Stack>
              )}
              <Stack gap={0} h="full" w={"62%"} p={"1"}>
                <Box lineClamp="2" fontSize="1.1em" fontWeight="700" lineHeight={"1"}>
                  {result?.name}
                </Box>
                <Box fontWeight="500" color={"gray"}>
                  {result?.age} Tahun
                </Box>
              </Stack>
            </HStack>
            <Box p={"1"} bg="blue.500" w={"fit-content"} shadow={"md"} borderRadius="full">
              <Box mx="1em" color="#fff" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                {`Tinggi: ${result?.height} cm | Berat: ${result?.weight} Kg`}
              </Box>
            </Box>
            <Box
              _hover={{
                transform: "scale(1.05)",
                transition: "all 0.2s ease-in-out",
              }}
            >
              <Box color="#3d1a16" fontFamily="Lobster" fontSize="2.5em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                {result?.bmi_score.toFixed(2)}
              </Box>
            </Box>
            <Stack justifyContent={"center"} alignItems={"center"} px="2em" h={"2.75em"} bg="green.400" w="fit-content" shadow={"md"} borderRadius="full">
              <Box color="#fff" fontFamily="Lobster" lineHeight={"1"} fontSize="1.25em" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
                {result?.status}
              </Box>
            </Stack>
            <Stack h={"5em"} justifyContent={"center"} alignItems={"center"}>
              <Blockquote alignContent={"center"} fontSize={".65em"} showDash cite={"ScaleUp"} citeUrl="#">
                {result?.suggestion}
              </Blockquote>
            </Stack>
          </Stack>
          <Button
            onClick={() => set_view("FORM")}
            w="full"
            bg="linear-gradient(135deg, #ff9a3c, #ff6f61)"
            color="white"
            fontWeight="bold"
            fontSize="lg"
            borderRadius="full"
            shadow="md"
            _hover={{
              transform: "scale(1.05)",
              transition: "all 0.2s ease-in-out",
            }}
            _active={{
              transform: "scale(0.98)",
            }}
            my="5"
          >
            Hitung Ulang
          </Button>
        </Stack>
      </Stack>
    </Container>
  );
};

export default BMISingle;

const LogoScaleUp = () => (
  <Box px="2em" mb="2em" bg="linear-gradient(135deg, #ff9a3c, #ff6f61)" w="fit-content" shadow={"md"} borderRadius="full">
    <Box color="#3d1a16" fontFamily="Lobster" fontSize="2.5em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
      ScaleUp
    </Box>
  </Box>
);

const AboutScaleUp = () => {
  return (
    <DialogRoot size={"sm"}>
      <DialogBackdrop />
      <DialogTrigger>
        <Icon pos={"absolute"} top={"2"} insetEnd={"2"} color={"gray.500"} fontSize={"2xl"}>
          <FcAbout />
        </Icon>
      </DialogTrigger>
      <DialogContent>
        <DialogCloseTrigger />
        <DialogHeader></DialogHeader>
        <DialogBody as={Stack} spaceY={"1em"}>
          <Box color="#3d1a16" fontFamily="Lobster" fontSize="2.5em" fontWeight="700" textAlign="center" textShadow="2px 2px 4px rgba(0, 0, 0, 0.2)">
            ScaleUp
          </Box>
          <Blockquote>
            ScaleUp adalah aplikasi sederhana namun efektif untuk membantu Anda memantau status kesehatan tubuh. Cukup masukkan tinggi dan berat badan, dan ScaleUp akan langsung memberi tahu apakah
            berat badan Anda ideal, kurang, atau berlebih. Dengan tampilan yang jelas dan kemudahan penggunaan, Anda bisa lebih sadar akan kondisi tubuh dan mengambil langkah yang tepat untuk hidup
            lebih sehat.
          </Blockquote>
        </DialogBody>
        <DialogFooter />
      </DialogContent>
    </DialogRoot>
  );
};
